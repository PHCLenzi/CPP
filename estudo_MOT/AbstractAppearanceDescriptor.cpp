/** @file
 *  @copyright HENSOLDT Optronics GmbH
 */

#include "AbstractAppearanceDescriptor.h"
#include "MotAppearanceDescriptors.h"

using namespace multi_object_tracking;

std::unique_ptr<AbstractAppearanceDescriptor> AbstractAppearanceDescriptor::create(AppearanceMethod method)
{
    if (method == AppearanceMethod::None)
        return nullptr;

    if (method == AppearanceMethod::ColorHistogram)
        return std::make_unique<ColorHistogram>();

    return std::make_unique<LBP>(method);
}
