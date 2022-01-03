#ifndef SIMPLEFVM_SOLVERALGORITHMCHOOSER_H
#define SIMPLEFVM_SOLVERALGORITHMCHOOSER_H

#include "FVMSolver/Solver.h"


namespace mainsolver {

class SolverAlgorithmChooser {

enum EnumAlgorithm {
    ALGORITHM_SIMPLE,
    ALGORITHM_SIMPLER,
    ALGORITHM_PISO
};

public:
    SolverAlgorithmChooser();

    void select_SIMPLE();
    void select_SIMPLER();
    void select_PISO();

    bool isSIMPLE();
    bool isSIMPLER();
    bool isPISO();

    void setUpSolverParameter(fvmsolver::Solver& solver);

private:
    EnumAlgorithm currentAlgorithm_ = ALGORITHM_SIMPLE;
};

}
#endif // SIMPLEFVM_SOLVERALGORITHMCHOOSER_H