#include "SolverFluidPropsDefiner.h"

namespace mainsolver {

SolverFluidPropsDefiner::SolverFluidPropsDefiner() {

}

void SolverFluidPropsDefiner::setDynamicViscosity(const double MU) {
    MU_ = MU;
}

void SolverFluidPropsDefiner::setDensity(const double RHO) {
    RHO_ = RHO;
}

void SolverFluidPropsDefiner::setUpSolverParameter(fvmsolver::Solver& solver) {
    solver.getDataManager().getFluidProperties().setMU(MU_);
    solver.getDataManager().getFluidProperties().setRHO(RHO_);
}

}