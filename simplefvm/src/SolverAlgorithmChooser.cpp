#include "SolverAlgorithmChooser.h"

#include "FVMSolver/Solver.h"

namespace mainsolver {

SolverAlgorithmChooser::SolverAlgorithmChooser() {

}

void SolverAlgorithmChooser::select_SIMPLE() {
    currentAlgorithm_ = ALGORITHM_SIMPLE;
}

void SolverAlgorithmChooser::select_SIMPLER() {
    currentAlgorithm_ = ALGORITHM_SIMPLER;
}

void SolverAlgorithmChooser::select_PISO() {
    currentAlgorithm_ = ALGORITHM_PISO;
}

bool SolverAlgorithmChooser::isSIMPLE() {
    if (ALGORITHM_SIMPLE == currentAlgorithm_) {
        return true;
    }
    else {
        return false;
    }
}

bool SolverAlgorithmChooser::isSIMPLER() {
    if (ALGORITHM_SIMPLER == currentAlgorithm_) {
        return true;
    }
    else {
        return false;
    }
}

bool SolverAlgorithmChooser::isPISO() {
    if (ALGORITHM_PISO == currentAlgorithm_) {
        return true;
    }
    else {
        return false;
    }
}

void SolverAlgorithmChooser::setUpSolverParameter(fvmsolver::Solver& solver) {
    switch (currentAlgorithm_) {
        case ALGORITHM_SIMPLE:
            solver.getSettingsManager().chooseAlgorithmSIMPLE();
            break;
        case ALGORITHM_SIMPLER:
            solver.getSettingsManager().chooseAlgorithmSIMPLER();
            break;
        case ALGORITHM_PISO:
            solver.getSettingsManager().chooseAlgorithmPISO();
            break;
        default:
            solver.getSettingsManager().chooseAlgorithmSIMPLE();
            break;
    }
}

}