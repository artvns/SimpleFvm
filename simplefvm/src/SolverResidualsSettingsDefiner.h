#ifndef SIMPLEFVM_SOLVERRESIDUALSSETTINGSDEFINER_H
#define SIMPLEFVM_SOLVERRESIDUALSSETTINGSDEFINER_H

#include "FVMSolver/Solver.h"


namespace mainsolver {

class Solver;

class SolverResidualsSettingsDefiner {
public:
    SolverResidualsSettingsDefiner();

    void selectConsoleOutput();
    void selectFileOutput(const std::string fullFileName);

    bool isConsoleOutput();
    bool isFileOutput();

    void setUpResidualsSettings(fvmsolver::Solver& solver);

private:
    bool isConsoleOutput_ = false;
    bool isFileOutput_ = false; 

    std::string fullFileName_ = "";
};

}
#endif // SIMPLEFVM_SOLVERRESIDUALSSETTINGSDEFINER_H