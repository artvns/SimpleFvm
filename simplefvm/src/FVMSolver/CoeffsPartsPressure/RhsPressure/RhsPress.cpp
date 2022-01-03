#include "RhsPress.h"

namespace fvmsolver {

RhsPress::RhsPress(uPtrDataPort spData) : 
                        spData_(std::move(spData)),
                        data_(*spData_),
                        uStar_(spData_->getUStar()),
                        vStar_(spData_->getVStar()) {

}

void RhsPress::calculate(size_t step) {
    double RHO_ = data_.getRHO();

    size_t num_ = data_.getNumPp(step) - 1;

    size_t nUStarW = data_.getNumUStarW(step);
    size_t nUStarE = data_.getNumUStarE(step);
    size_t nVStarN = data_.getNumVStarN(step);
    size_t nVStarS = data_.getNumVStarS(step);


    double dY = data_.get_dY(num_);
    double dX = data_.get_dX(num_);

    double uStarW = 0.0;
    double uStarE = 0.0;
    double vStarN = 0.0;
    double vStarS = 0.0;

    if (isNotZeroNumber(nUStarW)) {
        uStarW = uStar_.getValue(nUStarW - 1);
    }
    if (isNotZeroNumber(nUStarE)) {
        uStarE = uStar_.getValue(nUStarE - 1);
    }
    if (isNotZeroNumber(nVStarN)) {
        vStarN = vStar_.getValue(nVStarN - 1);
    }
    if (isNotZeroNumber(nVStarS)) {
        vStarS = vStar_.getValue(nVStarS - 1);
    }

    rhsValue_ = RHO_ * (uStarW - uStarE) * dY + RHO_ * (vStarS - vStarN) * dX;
}

double RhsPress::getRhsValue() {
    return rhsValue_;    
}

bool RhsPress::isNotZeroNumber(const size_t num) {
    if (num > 0) {
        return true;
    }
    else {
        return false;
    }
}

}