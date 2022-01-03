#include "DifferencingSchemeSettings.h"

namespace fvmsolver {

DifferencingSchemeSettings::DifferencingSchemeSettings() {

}

void DifferencingSchemeSettings::chooseCentral() {
    type_ = DIFF_SCHEME_CENTRAL;
}

void DifferencingSchemeSettings::chooseUpwind() {
    type_ = DIFF_SCHEME_UPWIND;
}

void DifferencingSchemeSettings::chooseHybrid() {
    type_ = DIFF_SCHEME_HYBRID;
}

EnumDifferencingScheme DifferencingSchemeSettings::getType() {
    return type_;
}

}