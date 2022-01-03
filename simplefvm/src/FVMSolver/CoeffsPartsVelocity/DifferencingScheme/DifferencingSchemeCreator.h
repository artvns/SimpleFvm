#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_DIFFERENCINGSCHEMECREATOR_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_DIFFERENCINGSCHEMECREATOR_H

#include <iostream>
#include <memory>

#include "FVMSolver/Tools/Enums/EnumDifferencingScheme.cpp"
#include "FVMSolver/SolverSettings/Config.h"

#include "IDifferencingScheme.h"
#include "CentralDifferencingScheme.h"
#include "UpwindDifferencingScheme.h"
#include "HybridDifferencingScheme.h"


namespace fvmsolver {

class DifferencingSchemeCreator {
public:
    DifferencingSchemeCreator(Config& config);

    std::shared_ptr<IDifferencingScheme> create();

private:
    Config& config_;
    const EnumDifferencingScheme schemeType_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_DIFFERENCINGSCHEMECREATOR_H