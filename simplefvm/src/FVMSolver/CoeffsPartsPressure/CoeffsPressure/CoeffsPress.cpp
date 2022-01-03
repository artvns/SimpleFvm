#include "CoeffsPress.h"

namespace fvmsolver {

CoeffsPress::CoeffsPress(uPtrDataPort spData) :
                                spData_(std::move(spData)),
                                data_(*spData_) {

}

void CoeffsPress::calculate(size_t step) {
    double RHO_ = data_.getRHO();

    size_t num = data_.getNumPp(step) - 1;

    size_t nUStarW = data_.getNumUStarW(step);
    size_t nUStarE = data_.getNumUStarE(step);
    size_t nVStarN = data_.getNumVStarN(step);
    size_t nVStarS = data_.getNumVStarS(step);

    double deUw_ = 0.0;
    double deUe_ = 0.0;
    double deVn_ = 0.0;
    double deVs_ = 0.0;

    if (isNotZeroNumber(nUStarW)) {
        deUw_ = data_.get_deU(nUStarW - 1);
    }
    if (isNotZeroNumber(nUStarE)) {
        deUe_ = data_.get_deU(nUStarE - 1);
    }
    if (isNotZeroNumber(nVStarN)) {
        deVn_ = data_.get_deV(nVStarN - 1);
    }
    if (isNotZeroNumber(nVStarS)) {
        deVs_ = data_.get_deV(nVStarS - 1);
    }

    a_w_ = RHO_ * deUw_ * data_.get_dY(num);
    a_e_ = RHO_ * deUe_ * data_.get_dY(num);
    a_n_ = RHO_ * deVn_ * data_.get_dX(num);
    a_s_ = RHO_ * deVs_ * data_.get_dX(num);
}


double CoeffsPress::getAw() {
    return a_w_;
}

double CoeffsPress::getAe() {
    return a_e_;
}

double CoeffsPress::getAn() {
    return a_n_;
}

double CoeffsPress::getAs() {
    return a_s_;
}


bool CoeffsPress::isNotZeroNumber(const size_t num) {
    if (num > 0) {
        return true;
    }
    else {
        return false;
    }
}

}