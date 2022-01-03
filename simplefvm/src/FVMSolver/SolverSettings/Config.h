#ifndef SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_CONFIG_H
#define SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_CONFIG_H

#include <string>

#include "BasicSolverVariables.h"
#include "FVMSolver/Tools/Enums/EnumAlgorithm.cpp"
#include "FVMSolver/Tools/Enums/EnumDifferencingScheme.cpp"


namespace fvmsolver {

struct Config {
    EnumAlgorithm               algorithm;
    EnumDifferencingScheme      differencingScheme;
    bool                        isResidsOutputConsole;
    bool                        isResidsOutputFile;
    BasicSolverVariables        basicSolverVariables;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_CONFIG_H