#ifndef SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_DIFFERENCINGSCHEMESETTINGS_H
#define SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_DIFFERENCINGSCHEMESETTINGS_H

#include "FVMSolver/Tools/Enums/EnumDifferencingScheme.cpp"
#include "CustomExceptions/SolverSettingsException.h"


namespace fvmsolver {

class DifferencingSchemeSettings {
public:
    DifferencingSchemeSettings();

    void chooseCentral();
    void chooseUpwind();
    void chooseHybrid();

    EnumDifferencingScheme getType();

private:
    EnumDifferencingScheme type_ = DIFF_SCHEME_NOT_CHOSEN;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_DIFFERENCINGSCHEMESETTINGS_H