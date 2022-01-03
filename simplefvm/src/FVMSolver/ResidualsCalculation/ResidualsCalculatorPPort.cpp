#include "ResidualsCalculatorPPort.h"

namespace fvmsolver {

ResidualsCalculatorPPort::ResidualsCalculatorPPort(
                const SolverCellNumsInteriorMask& numsInterior,
                SavedRhsStore& savedRhs) : 
                                numsInterior_(numsInterior),
                                savedRhs_(savedRhs) {

}

size_t ResidualsCalculatorPPort::getInterNumPp(const size_t step) const {
    return numsInterior_.getCellNumP(step);
}

double ResidualsCalculatorPPort::getRhs(const size_t pos) const {
    return savedRhs_.getRhs(pos);
}

}