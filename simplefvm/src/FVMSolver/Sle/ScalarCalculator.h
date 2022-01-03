#ifndef SIMPLEFVM_FVMSOLVER_SLE_SCALARCALCULATOR_H
#define SIMPLEFVM_FVMSOLVER_SLE_SCALARCALCULATOR_H

#include <memory>

#include "FVMSolver/MatrixBuilder/SleMatrixBuilder.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/SleSolver.h"


namespace fvmsolver {

class ScalarCalculator {
public:
    ScalarCalculator(std::shared_ptr<SleSolver> spSleSolver, 
                        std::shared_ptr<SleMatrixBuilder> sleMatrixes);

    void calculate();

private:
    std::shared_ptr<SleSolver> spSleSolver_ = nullptr;
    std::shared_ptr<SleMatrixBuilder> sleMatrixes_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SLE_SCALARCALCULATOR_H