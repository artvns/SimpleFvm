#ifndef SIMPLEFVM_FVMSOLVER_SLE_SCALARCALCULATORCREATOR_H
#define SIMPLEFVM_FVMSOLVER_SLE_SCALARCALCULATORCREATOR_H

#include <memory>

#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/MatrixBuilder/SleMatrixBuilderCreator.h"

#include "ScalarCalculator.h"


namespace fvmsolver {

class ScalarCalculatorCreator {
public:
    ScalarCalculatorCreator(MathToolsManager& mathToolsManager, 
                            SleMatrixBuilderCreator& sleMatrixBuilderCreator);

    std::shared_ptr<ScalarCalculator> createUStarCalculator();
    std::shared_ptr<ScalarCalculator> createVStarCalculator();
    std::shared_ptr<ScalarCalculator> createPPrimeCalculator();

private:
    MathToolsManager& mathToolsManager_; 
    SleMatrixBuilderCreator& sleMatrixBuilderCreator_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SLE_SCALARCALCULATORCREATOR_H