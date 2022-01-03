#ifndef SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_ALGORITHMSETTINGS_H
#define SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_ALGORITHMSETTINGS_H

#include "FVMSolver/Tools/Enums/EnumAlgorithm.cpp"
#include "CustomExceptions/SolverSettingsException.h"


namespace fvmsolver {

class AlgorithmSettings {
public:
    AlgorithmSettings();

    void chooseSIMPLE();
    void chooseSIMPLER();
    void choosePISO();

    EnumAlgorithm getType();

private:
    EnumAlgorithm type_ = ALGORITHM_NOT_CHOSEN;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_ALGORITHMSETTINGS_H