/** @file
 *  @copyright HENSOLDT Optronics GmbH
 */

#include "MotTrackManager.h"

#include <vector>
#include <algorithm>
#include <cmath>

#include "ImageRegistration.h"
#include "MotMotionModel.h"
#include "Utilities.h"

using namespace multi_object_tracking;

MotTrackManager::MotTrackManager(MotionModelType motionModelType)
    : m_motionModelType(motionModelType)
    , m_imageRegistration{std::make_unique<ImageRegistration>()}
{
}

std::vector<std::shared_ptr<Track>>& MotTrackManager::getActiveTracks()
{
    return m_activeTracks;
}

void MotTrackManager::setActiveTracks(const std::vector<std::shared_ptr<Track>>& tracks)
{
    m_activeTracks = tracks;
}

void MotTrackManager::reinit(const cv::Size& size)
{
    m_imageSize = size;
    m_imageRegistration->resetReferenceImage();
}

void MotTrackManager::update(const std::vector<Detection>& remainingDetections,
                             AppearanceMethod              appearanceMethod,
                             const cv::UMat&               currentFrame,
                             AssociationMethod             associationMethod)
{
    if (m_motionModelType != MotionModelType::None) {
        determineControlVector(currentFrame);
    }

    updateTracks();
    removeTrackDuplicates(associationMethod);
    newDetectionsToTracks(remainingDetections, appearanceMethod, currentFrame);
}

void MotTrackManager::determineControlVector(const cv::UMat& currentImage)
{
    // register image to set up control vector
    cv::Mat  htm = cv::Mat::eye(3, 3, CV_64F);
    cv::UMat grayCurrentImage;
    cv::cvtColor(currentImage, grayCurrentImage, cv::COLOR_BGR2GRAY);
    m_imageRegistration->registerImage(grayCurrentImage, htm);

    // we only consider translational motion up to now
    cv::Mat control(2, 1, CV_32F);
    control.at<float>(0) = static_cast<float>(htm.at<double>(0, 2)); // dX
    control.at<float>(1) = static_cast<float>(htm.at<double>(1, 2)); // dY
    setControlVector(control);
}

cv::Mat MotTrackManager::getControlVector() const
{
    return m_controlVector;
}

void MotTrackManager::setControlVector(const cv::Mat& controlVector)
{
    m_controlVector = controlVector;
}

void MotTrackManager::updateTracks()
{
    if (m_activeTracks.empty())
        return;

    // variables created to reduce the size of the following equation
    int detectionConfidence{0};
    int trackConfidence{0};
    int lifeTime{0};
    for (auto it = m_activeTracks.begin(); it != m_activeTracks.end();) {
        auto currTrack = *it;
        currTrack->lifeTimeCounter++;

        // handles the track life time
        if (!currTrack->associatedDetections.empty()) {
            currTrack->lostTimeCounter = 0;
            currTrack->trackingState   = TrackingState::Tracking;
        }

        if (currTrack->lostTimeCounter > 0)
            currTrack->trackingState = TrackingState::Searching;

        if (absenceTimeHandler(currTrack)) {
            currTrack->trackingState = TrackingState::Lost;
            m_lostTracks.emplace_back(currTrack);
            it = m_activeTracks.erase(it);
            continue;
        }

        // calculates the confidence of the track using an incremental average
        detectionConfidence   = int(currTrack->associatedDetections[0].confidence);
        trackConfidence       = int(currTrack->confidence);
        lifeTime              = int(currTrack->lifeTimeCounter);
        currTrack->confidence = size_t(trackConfidence + (detectionConfidence - trackConfidence) / lifeTime);
        assert(currTrack->confidence <= 10000);

        // update the track history
        currTrack->history.emplace(currTrack->history.begin(), currTrack->boundingBox);

        // update the track bounding box
        if (m_motionModelType == MotionModelType::None) {
            currTrack->boundingBox        = currTrack->associatedDetections[0].boundingBox;
            currTrack->boundingBox.width  = .8f * currTrack->history[0].width + .2f * currTrack->boundingBox.width;
            currTrack->boundingBox.height = .8f * currTrack->history[0].height + .2f * currTrack->boundingBox.height;
        } else {
            if (currTrack->trackingState == TrackingState::Searching) {
                cv::Rect2f predictedBoundingBox;
                if (currTrack->motionModel->predict(currTrack, getControlVector(), predictedBoundingBox))
                    currTrack->boundingBox = predictedBoundingBox;
                else
                    currTrack->boundingBox = currTrack->associatedDetections[0].boundingBox;
            } else if (currTrack->trackingState == TrackingState::Tracking) {
                currTrack->motionModel->filter(currTrack, getControlVector());
            }
        }

        if (!trackValid(currTrack)) {
            currTrack->trackingState = TrackingState::Lost;
            m_lostTracks.emplace_back(currTrack);
            it = m_activeTracks.erase(it);
            continue;
        }

        ++it;
    }
}

bool MotTrackManager::absenceTimeHandler(std::shared_ptr<Track>& track) const
{
    size_t absenceTime{m_maxAbsenceTime};

    // absence time not greater than the maximal life time
    absenceTime = track->lifeTimeCounter < absenceTime ? track->lifeTimeCounter : absenceTime;

    // absence time proportional to the number of frames with predictions without an association
    auto absenceRate = float(track->lostTimeCounter) > float(m_maxAbsenceTime) ? 1 : float(track->lostTimeCounter)/float(m_maxAbsenceTime);
    absenceTime = size_t((1 - absenceRate) * float(absenceTime));

    // lower absence time when object is closer to the borders
    auto xDiff = track->boundingBox.x + track->boundingBox.width/2 - float(m_imageSize.width)/2;
    auto yDiff = track->boundingBox.y + track->boundingBox.height/2 - float(m_imageSize.height)/2;
    auto distance = sqrt(pow(xDiff, 2) + pow(yDiff, 2));
    auto maxDistance = sqrt(pow(float(m_imageSize.width)/2, 2) + pow(float(m_imageSize.height)/2, 2));
    absenceTime = size_t((1 - distance/maxDistance) * double(absenceTime));

    return track->lostTimeCounter > absenceTime;
}

bool MotTrackManager::trackValid(std::shared_ptr<Track>& track) const
{
    cv::Rect2f imageRect{0, 0, float(m_imageSize.width), float(m_imageSize.height)};
    cv::Rect2f unionRect{track->boundingBox | imageRect};

    return track->boundingBox.area() > 0 && !(unionRect.area() > imageRect.area());
}

void MotTrackManager::removeTrackDuplicates(AssociationMethod associationMethod)
{
    if (m_activeTracks.empty())
        return;

    // generates a duplicate matrix to provide information of potential duplicated tracks
    std::vector<std::vector<unsigned>>            duplicateMatrix(m_activeTracks.size(), std::vector<unsigned>(m_activeTracks.size(), 0));
    auto                                          rowIterator = m_activeTracks.begin();
    std::vector<std::shared_ptr<Track>>::iterator colIterator;
    float                                         result{0.f};
    std::unique_ptr<AbstractDataAssociation>      associationDescriptor;
    associationDescriptor = AbstractDataAssociation::create(associationMethod);
    for (unsigned int rowIndex = 0; rowIterator != m_activeTracks.end(); ++rowIterator, ++rowIndex) {
        colIterator = m_activeTracks.begin() + rowIndex + 1;
        for (unsigned int colIndex = rowIndex + 1; colIterator != m_activeTracks.end(); ++colIterator, ++colIndex) {
            associationDescriptor->calculateAssociation((*rowIterator)->boundingBox, (*colIterator)->boundingBox, result);
            if (result >= m_duplicateThreshold) {
                duplicateMatrix[rowIndex][colIndex] = 1;
            } else {
                duplicateMatrix[rowIndex][colIndex] = 0;
            }
        }
    }

    // determines which tracks have to be removed
    std::vector<int> duplicateVector;
    for (unsigned int i = 0; i < m_activeTracks.size(); i++) {
        unsigned int sumCol{0};
        for (unsigned int j = 0; j < m_activeTracks.size(); j++) {
            sumCol = sumCol + duplicateMatrix[j][i];
        }
        duplicateVector.emplace_back(sumCol);
    }

    // removes the duplicated tracks
    auto duplicateIterator = duplicateVector.begin();
    auto trackIterator     = m_activeTracks.begin();
    for (; duplicateIterator != duplicateVector.end(); ++duplicateIterator) {
        if (*duplicateIterator >= 1) {
            trackIterator = m_activeTracks.erase(trackIterator);
        } else
            ++trackIterator;
    }
}

void MotTrackManager::newDetectionsToTracks(const std::vector<Detection>& remainingDetections,
                                            AppearanceMethod              appearanceMethod,
                                            const cv::UMat&               currentFrame)
{
    if (remainingDetections.empty())
        return;

    std::shared_ptr<Track> track;

    // creates the tracks based on the incoming detections
    for (const auto& remainingDetection : remainingDetections) {
        if (remainingDetection.confidence >= m_confidenceThreshold) {
            track                  = createTrack();
            track->boundingBox     = remainingDetection.boundingBox;
            track->trackingState   = TrackingState::Tracking;
            track->lifeTimeCounter = 1;
            track->lostTimeCounter = 0;
            track->confidence      = remainingDetection.confidence;
            track->motionModel     = std::make_unique<MotMotionModel>(m_motionModelType, remainingDetection.boundingBox, currentFrame);
            track->associatedDetections.emplace_back(remainingDetection);
            setNewTrackId(remainingDetection, appearanceMethod, currentFrame, track);

            m_activeTracks.emplace_back(track);
        }
    }
}

std::shared_ptr<Track> MotTrackManager::createTrack()
{
    return std::make_shared<Track>();
}

void MotTrackManager::setNewTrackId(const Detection&              detection,
                                    AppearanceMethod              appearanceMethod,
                                    const cv::UMat&               currentFrame,
                                    const std::shared_ptr<Track>& newTrack)
{
    // establishes the appearance method and its distance threshold parameter
    switch (appearanceMethod) {
        case AppearanceMethod::None:
            newTrack->id = m_globalId++;
            return;
        case AppearanceMethod::ColorHistogram:
            m_distanceThreshold = 0.22; // empirically determined
            break;
        default:
            m_distanceThreshold = 0.04; // empirically determined
            break;
    }

    std::vector<float>                            newTrackAppearance;
    cv::Mat                                       frameAsMat = currentFrame.getMat(cv::ACCESS_READ);
    std::vector<double>                           distances;
    std::vector<size_t>                           appearanceIds;
    std::uint64_t                                 minIndex{0};
    std::unique_ptr<AbstractAppearanceDescriptor> appearanceDescriptor = AbstractAppearanceDescriptor::create(appearanceMethod);

    // Set new object appearance
    appearanceDescriptor->calculateAppearance(cropObject(frameAsMat, detection.boundingBox), newTrackAppearance);
    newTrack->appearance = newTrackAppearance;

    // Set new object Id
    if (!m_lostTracks.empty()) {

        for (auto& inactiveTrack : m_lostTracks) {
            distances.emplace_back(calculateHellingerDistance(newTrackAppearance, inactiveTrack->appearance));
            appearanceIds.emplace_back(inactiveTrack->id);
        }
        minIndex = std::uint64_t(std::distance(distances.begin(), std::min_element(distances.begin(), distances.end())));

        // if the minimal distance is lower than the distance threshold, the object is recognized
        if (distances[minIndex] <= m_distanceThreshold) {
            newTrack->id = appearanceIds[minIndex];

            const auto it
                = std::find_if(m_lostTracks.begin(), m_lostTracks.end(), [&](const auto& lostTrack) { return lostTrack->id == newTrack->id; });
            if (it != m_lostTracks.end())
                m_lostTracks.erase(it);

        }
        // if the minimal distance is higher than the distance threshold, the object is not recognized
        else {
            newTrack->id = m_globalId++;
        }

    } else {
        // if the appearance library is empty
        newTrack->id = m_globalId++;
    }
}

MotionModelType MotTrackManager::getMotionModelType() const
{
    return m_motionModelType;
}

void MotTrackManager::setMotionModelType(MotionModelType motionModel)
{
    m_motionModelType = motionModel;
}

size_t MotTrackManager::getMaxAbsenceTime() const
{
    return m_maxAbsenceTime;
}

void MotTrackManager::setMaxAbsenceTime(size_t maxAbsenceTime)
{
    m_maxAbsenceTime = maxAbsenceTime;
}

size_t MotTrackManager::getConfidenceThreshold() const
{
    return m_confidenceThreshold;
}

void MotTrackManager::setConfidenceThreshold(size_t confidenceThreshold)
{
    m_confidenceThreshold = confidenceThreshold;
}
