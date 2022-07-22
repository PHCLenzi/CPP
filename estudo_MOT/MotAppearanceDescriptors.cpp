/** @file
 *  @copyright HENSOLDT Optronics GmbH
 */

#include "MotAppearanceDescriptors.h"

#include <numeric>
#include <iostream>
#include <cassert>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

#include "Utilities.h"

using namespace multi_object_tracking;

void ColorHistogram::calculateAppearance(const cv::Mat& mask, std::vector<float>& concatenated)
{
    auto                 maskPixelAmount = float(mask.rows * mask.cols * 3); // 3 channels
    int                  histSize{256};
    float                range[]     = {0, 256};
    const float*         histRange[] = {range};
    cv::Mat              hist;
    std::vector<cv::Mat> channels;
    cv::split(mask, channels);
    float sum{.0f};
    float element{.0f};

    for (const auto& channel : channels) {
        cv::calcHist(&channel, 1, 0, cv::Mat(), hist, 1, &histSize, histRange, true, false);
        hist /= maskPixelAmount;

        for (int i = 0; i < int(hist.rows); i++) {
            element = hist.at<float>(i, 0);
            concatenated.emplace_back(element);
            sum += element;
        }
    }

    // verifies if the sum of the elements is equal to one. the 1e-4 is preferable instead of DBL_EPSILON because of rounding issues in this
    // case.
    assert(1. - sum < 1e-4);
}

LBP::LBP(AppearanceMethod lbpMethod)
    : m_lbpMethod{lbpMethod}
{
}

void LBP::calculateAppearance(const cv::Mat& mask, std::vector<float>& concatenated)
{
    cv::Mat              hist;
    std::vector<cv::Mat> channels;
    cv::split(mask, channels);
    float sum{.0f};
    float element{.0f};

    for (const auto& channel : channels) {
        calculateLocalBinaryPatterns(channel, m_lbpMethod, hist);

        for (int i = 0; i < int(hist.rows); i++) {
            element = hist.at<float>(i, 0);
            concatenated.emplace_back(element);
            sum += element;
        }
    }

    // verifies if the sum of the elements is equal to one. the 1e-4 is preferable instead of DBL_EPSILON because of rounding issues in this
    // case.
    assert(1. - sum < 1e-4);
}

void LBP::calculateLocalBinaryPatterns(const cv::Mat& imageInput, AppearanceMethod method, cv::Mat& hist)
{
    if (imageInput.empty())
        return;

    int          histSize{10};
    float        range[]     = {0, 0};
    const float* histRange[] = {range};
    cv::Mat      imageOutput;

    if (method == AppearanceMethod::VARLBP) {
        VARLBP_<unsigned char>(imageInput, imageOutput);
        histSize     = 16;
        range[1]     = 16385; // the maximal value that can be reached for points = 8 and radius = 1 is (256 graylevels / 2) ^ 2 + 1.
        histRange[0] = range;
        cv::calcHist(&imageOutput, 1, 0, cv::Mat(), hist, 1, &histSize, histRange, true, false);
        hist /= float(imageOutput.rows * imageOutput.cols * 3); // 3 channels

    } else if (method == AppearanceMethod::OLBP) {
        OLBP_<unsigned char>(imageInput, imageOutput);
        range[1]     = 256; // this implementation of LBP reaches 255 as maximum value.
        histRange[0] = range;
        cv::calcHist(&imageOutput, 1, 0, cv::Mat(), hist, 1, &histSize, histRange, true, false);
        hist /= float(imageOutput.rows * imageOutput.cols * 3); // 3 channels

    } else if (method == AppearanceMethod::XCSLBP) {
        XCSLBP_<unsigned char>(imageInput, imageOutput);
        range[1]     = 16; // this implementation of LBP reaches 15 as maximum value.
        histRange[0] = range;
        cv::calcHist(&imageOutput, 1, 0, cv::Mat(), hist, 1, &histSize, histRange, true, false);
        hist /= float(imageOutput.rows * imageOutput.cols * 3); // 3 channels

    } else if (method == AppearanceMethod::SILTP) {
        SILTP_<unsigned char>(imageInput, imageOutput);
        range[1]     = 81; // this implementation of LBP reaches 80 as maximum value.
        histRange[0] = range;
        cv::calcHist(&imageOutput, 1, 0, cv::Mat(), hist, 1, &histSize, histRange, true, false);
        hist /= float(imageOutput.rows * imageOutput.cols * 3); // 3 channels

    } else if (method == AppearanceMethod::OLBPandVARLBP) {
        cv::Mat olbpOutput;
        cv::Mat olbpHist;
        cv::Mat varlbpOutput;
        cv::Mat varlbpHist;

        OLBP_<unsigned char>(imageInput, olbpOutput);
        range[1]     = 256; // this implementation of LBP reaches 255 as maximum value.
        histRange[0] = range;
        cv::calcHist(&olbpOutput, 1, 0, cv::Mat(), olbpHist, 1, &histSize, histRange, true, false);
        olbpHist /= float(olbpOutput.rows * olbpOutput.cols * 3 * 2); // 3 channels, 2 histograms

        VARLBP_<unsigned char>(imageInput, varlbpOutput);
        histSize     = 16;
        range[1]     = 16385; // the maximal value that can be reached for points = 8 and radius = 1 is (256 graylevels / 2) ^ 2 + 1.
        histRange[0] = range;
        cv::calcHist(&varlbpOutput, 1, 0, cv::Mat(), varlbpHist, 1, &histSize, histRange, true, false);

        cv::vconcat(olbpHist, varlbpHist, hist);
        hist /= float(hist.rows * hist.cols);
    }
}
