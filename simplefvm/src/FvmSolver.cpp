#include "FvmSolver.h"

namespace mainsolver {

FvmSolver::FvmSolver() : solver_(dataStores_),
                         solverMeshLoader_(dataStores_),
                         solverFVMSolver_(solver_, dataStores_),
                         solverResultsSaver_(dataStores_) {

}

FvmSolver::~FvmSolver() {
    
}

void FvmSolver::setAlgorithm(SolverAlgorithmChooser& algirithm) {
    algirithm.setUpSolverParameter(solver_);
}

void FvmSolver::setFluidProps(SolverFluidPropsDefiner& fluidPropsDefiner) {
    fluidPropsDefiner.setUpSolverParameter(solver_);
}

void FvmSolver::setScheme(SolverSchemeChooser& scheme) {
    scheme.setUpSolverParameter(solver_);
}

void FvmSolver::setSleSolver(SolverSleSolverChooser& sleSolver) {
    sleSolver.setUpSolverParameter(solver_);
}

void FvmSolver::setBoundaryConditions(SolverPartTypeChooser& bc) {
    bc.setUpBcConditions(solver_);
}

void FvmSolver::setResidualsSettings(
                    SolverResidualsSettingsDefiner& residsSettings) {
    residsSettings.setUpResidualsSettings(solver_);
}

SolverMeshLoader& FvmSolver::getSolverMeshLoader() {
    return solverMeshLoader_;
}

SolverFVMSolver& FvmSolver::getSolverFVMSolver() {
    return solverFVMSolver_;
}

SolverResultsSaver& FvmSolver::getSolverResultsSaver() {
    return solverResultsSaver_;
}

}