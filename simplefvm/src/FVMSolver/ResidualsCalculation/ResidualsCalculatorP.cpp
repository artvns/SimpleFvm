#include "ResidualsCalculatorP.h"

namespace fvmsolver {

ResidualsCalculatorP::ResidualsCalculatorP(
                    uPtrDataPort spData) :
                            spData_(std::move(spData)),
                            data_(*spData_) {

}

double ResidualsCalculatorP::calculateCellResidual(size_t step) {
    size_t numPp = data_.getInterNumPp(step) - 1;

    residual_ = std::abs(data_.getRhs(numPp));

    return residual_;
}

}