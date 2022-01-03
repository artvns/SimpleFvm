#include "RhsU.h"

namespace fvmsolver {

RhsU::RhsU(uPtrDataPort spData) : 
                spData_(std::move(spData)),
                data_(*spData_) {

}

void RhsU::calculate(size_t step, double Sc, double a_p) {
    size_t nUp = data_.getNumUp(step) - 1;
    size_t nUw = data_.getNumUw(step) - 1;

    double dY = data_.get_dY(step);

    double uP     = data_.get_u(nUp);
    double pressP = data_.get_p(nUp);
    double pressW = data_.get_p(nUw);

    double alpha_ = data_.get_alphaU();

    bValue_ = Sc + (((1.0 - alpha_) * a_p / alpha_) * uP);
    rhsValue_ = (pressW - pressP) * dY + bValue_;
}

}