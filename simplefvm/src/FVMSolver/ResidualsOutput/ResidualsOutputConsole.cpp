#include "ResidualsOutputConsole.h"

namespace fvmsolver {

ResidualsOutputConsole::ResidualsOutputConsole() {

}

void ResidualsOutputConsole::saveStepResiduals(size_t stepNumber) {
    std::cout << "<-------  Calculated residuals  ------->  " << '\n';
    std::cout << "<-------  Residual U: " << residualU_ << "  ------->  " << '\n';
    std::cout << "<-------  Residual V: " << residualV_ << "  ------->  " << '\n';
    std::cout << "<-------  Residual P: " << residualP_ << "  ------->  " << '\n';
    std::cout << "<-------  Step: " << stepNumber + 1 << "  ------->  " << '\n';
}

}