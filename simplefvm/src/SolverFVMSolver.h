#ifndef SIMPLEFVM_SOLVERFVMSOLVER_H
#define SIMPLEFVM_SOLVERFVMSOLVER_H

#include <cstddef>
#include <string>
#include <stdexcept>
#include <ostream>

#include "DataStores/GlobalDataStores.h"
#include "FVMSolver/Solver.h"

#include "CustomExceptions/SolverSettingsException.h"
#include "CustomExceptions/FluidPropertiesEcxeption.h"
#include "CustomExceptions/SleSolverException.h"
#include "CustomExceptions/PreparatoryOperationsException.h"
#include "CustomExceptions/BoundaryConditionsException.h"


namespace mainsolver {

class Solver;
class GlobalDataStores;

class SolverFVMSolver {
public:
    SolverFVMSolver(fvmsolver::Solver& solver,
                    datastores::GlobalDataStores& dataStores);

    void startCalculation(const size_t numberOfIterations);

private:
    fvmsolver::Solver& solver_;
    datastores::GlobalDataStores& dataStores_;
};

}
#endif // SIMPLEFVM_SOLVERFVMSOLVER_H