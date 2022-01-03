#include "RhsV.h"

namespace fvmsolver {

RhsV::RhsV(uPtrDataPort spData) : 
                spData_(std::move(spData)),
                data_(*spData_) {

}

void RhsV::calculate(size_t step, double Sc, double a_p) {
    size_t nVp = data_.getNumVp(step) - 1;
    size_t nVs = data_.getNumVs(step) - 1;

    double dX = data_.get_dX(step);

    double vP     = data_.get_v(nVp);
    double pressP = data_.get_p(nVp);
    double pressS = data_.get_p(nVs);

    double alpha_ = data_.get_alphaV();

    bValue_ = Sc + (((1.0 - alpha_) * a_p / alpha_) * vP);
    rhsValue_ = (pressS - pressP) * dX + bValue_;
}

}