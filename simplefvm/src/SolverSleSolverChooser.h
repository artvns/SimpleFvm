#ifndef SIMPLEFVM_SOLVERSLESOLVERCHOOSER_H
#define SIMPLEFVM_SOLVERSLESOLVERCHOOSER_H

#include <memory>

#include "FVMSolver/Solver.h"
#include "MathTools/SleSolvers/EigenLib/SleSolverEigen.h"


namespace mainsolver {

class Solver;

class SolverSleSolverChooser {
private:
    using shPtrISleSolver = std::shared_ptr<mathtools::ISleSolver>;
    using shPtrSleSolverEigen = std::shared_ptr<mathtools::SleSolverEigen>;

public:
    SolverSleSolverChooser();

    void select_EIGEN_SOLVER();

    void setUpSolverParameter(fvmsolver::Solver& solver);

private:
    shPtrISleSolver spSleSolverU_ = nullptr;
    shPtrISleSolver spSleSolverV_ = nullptr;
    shPtrISleSolver spSleSolverP_ = nullptr;
};

}
#endif // SIMPLEFVM_SOLVERSLESOLVERCHOOSER_H