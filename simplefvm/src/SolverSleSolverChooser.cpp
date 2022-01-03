#include "SolverSleSolverChooser.h"

namespace mainsolver {

SolverSleSolverChooser::SolverSleSolverChooser() {

}

void SolverSleSolverChooser::select_EIGEN_SOLVER() {
    spSleSolverU_ = shPtrSleSolverEigen(new mathtools::SleSolverEigen());
    spSleSolverV_ = shPtrSleSolverEigen(new mathtools::SleSolverEigen());
    spSleSolverP_ = shPtrSleSolverEigen(new mathtools::SleSolverEigen());
}

void SolverSleSolverChooser::setUpSolverParameter(fvmsolver::Solver& solver) {
    solver.getMathToolsManager().setSleSoverP(*spSleSolverP_);
    solver.getMathToolsManager().setSleSoverU(*spSleSolverU_);
    solver.getMathToolsManager().setSleSoverV(*spSleSolverV_);
}

}