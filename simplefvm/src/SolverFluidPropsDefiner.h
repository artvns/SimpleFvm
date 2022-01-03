#ifndef SIMPLEFVM_SOLVERFLUIDPROPSDEFINER_H
#define SIMPLEFVM_SOLVERFLUIDPROPSDEFINER_H

#include "FVMSolver/Solver.h"


namespace mainsolver {

class Solver;

class SolverFluidPropsDefiner {
public:
    SolverFluidPropsDefiner();

    void setDynamicViscosity(const double MU);
    void setDensity(const double RHO);

    void setUpSolverParameter(fvmsolver::Solver& solver);

private:
    double MU_ = 0.0;
    double RHO_ = 0.0;
};

}
#endif // SIMPLEFVM_SOLVERFLUIDPROPSDEFINER_H