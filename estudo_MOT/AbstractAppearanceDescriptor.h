/** @file
 *  @copyright HENSOLDT Optronics GmbH
 */

#pragma once

#include <opencv2/core.hpp>

#include "MotTypes.h"

namespace multi_object_tracking {

/**
 * @class Base class for appearance descriptors.
 *
 * This is the base class for appearance descriptors of the multi-object tracking algorithms.
 */
class AbstractAppearanceDescriptor
{
public:
    AbstractAppearanceDescriptor()                                    = default;
    virtual ~AbstractAppearanceDescriptor()                           = default;
    AbstractAppearanceDescriptor(AbstractAppearanceDescriptor&&)      = delete;
    AbstractAppearanceDescriptor(const AbstractAppearanceDescriptor&) = delete;
    AbstractAppearanceDescriptor& operator=(AbstractAppearanceDescriptor&&) = delete;
    AbstractAppearanceDescriptor& operator=(const AbstractAppearanceDescriptor&) = delete;

    /**
     * @brief Calculate an appearance feature vector.
     */
    virtual void calculateAppearance(const cv::Mat& mask, std::vector<float>& concatenated) = 0;

    /**
     * @brief Factory method that creates objects for appearance description.
     * @param[in] appearance description method.
     * @return returns the pointer to the just created appearance description object.
     */
    static std::unique_ptr<AbstractAppearanceDescriptor> create(AppearanceMethod method);

protected:
};
}
