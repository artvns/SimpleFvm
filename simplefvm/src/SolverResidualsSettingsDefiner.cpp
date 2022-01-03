#include "SolverResidualsSettingsDefiner.h"

namespace mainsolver {

SolverResidualsSettingsDefiner::SolverResidualsSettingsDefiner() {

}

void SolverResidualsSettingsDefiner::selectConsoleOutput() {
    isConsoleOutput_ = true;
}

void SolverResidualsSettingsDefiner::selectFileOutput(
                            const std::string fullFileName) {

    isFileOutput_ = true;                       
    fullFileName_ = fullFileName;   
}

void SolverResidualsSettingsDefiner::setUpResidualsSettings(
                                            fvmsolver::Solver& solver) {

    if (isConsoleOutput_) {
        solver.getSettingsManager().chooseResidualsOutputConsole();
    }

    if (isFileOutput_) {
        solver.getSettingsManager().chooseResidualsOutputFile(fullFileName_);
    }
}


bool SolverResidualsSettingsDefiner::isConsoleOutput() {
    if (isConsoleOutput_) {
        return true;
    } else {
        return false;
    }
}

bool SolverResidualsSettingsDefiner::isFileOutput() {
    if (isFileOutput_) {
        return true;
    } else {
        return false;
    }
}

}