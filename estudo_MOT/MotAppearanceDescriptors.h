/** @file
 *  @copyright HENSOLDT Optronics GmbH
 */

#pragma once

#include <map>
#include <string>

#include <opencv2/core.hpp>

#include "AbstractAppearanceDescriptor.h"
#include "MotTypes.h"

namespace multi_object_tracking {
class ColorHistogram final : public AbstractAppearanceDescriptor
{
public:
    ColorHistogram()                      = default;
    ~ColorHistogram()                     = default;
    ColorHistogram(ColorHistogram&&)      = delete;
    ColorHistogram(const ColorHistogram&) = delete;
    ColorHistogram& operator=(ColorHistogram&&) = delete;
    ColorHistogram& operator=(const ColorHistogram&) = delete;

    /**
     * @brief Generates an appearance feature vector based on color histogram.
     * @param[in] mask the mask which provides the color information from.
     * @param[in,out] concatenated the feature vector.
     */
    void calculateAppearance(const cv::Mat& mask, std::vector<float>& concatenated) override;
};

class LBP final : public AbstractAppearanceDescriptor
{
public:
    explicit LBP(AppearanceMethod lbp_method);
    ~LBP()          = default;
    LBP(LBP&&)      = delete;
    LBP(const LBP&) = delete;
    LBP& operator=(LBP&&) = delete;
    LBP& operator=(const LBP&) = delete;

    /**
     * @brief Generates an appearance feature vector based on color histogram.
     * @param[in] mask the mask which provides the color information from.
     * @param[in,out] concatenated the feature vector.
     */
    void calculateAppearance(const cv::Mat& mask, std::vector<float>& concatenated) override;

private:
    const AppearanceMethod m_lbpMethod;

    void calculateLocalBinaryPatterns(const cv::Mat& imageInput, AppearanceMethod method, cv::Mat& hist);
};
}
