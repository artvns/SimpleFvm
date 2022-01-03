#include "ResidualsCalculatorU.h"

namespace fvmsolver {

ResidualsCalculatorU::ResidualsCalculatorU(
                        uPtrDataPort spData) :
                                spData_(std::move(spData)),
                                data_(*spData_),
                                uStar_(spData_->getUStar()),
                                coeffAp_(spData_->getAp()),
                                coeffAw_(spData_->getAw()),
                                coeffAe_(spData_->getAe()),
                                coeffAn_(spData_->getAn()),
                                coeffAs_(spData_->getAs()) {

}

double ResidualsCalculatorU::calculateCellResidual(const size_t step) {
    size_t numUp = data_.getInterNumUp(step);
    size_t numUw = data_.getInterNumUw(step);
    size_t numUe = data_.getInterNumUe(step);
    size_t numUn = data_.getInterNumUn(step);
    size_t numUs = data_.getInterNumUs(step);

    double nbSum = 0.0;

    if (isCoeffExists(numUw)) {
        size_t posW = numUw - 1;
        nbSum += coeffAw_[posW] * uStar_.getValue(posW);
    }
    if (isCoeffExists(numUe)) {
        size_t posE = numUe - 1;
        nbSum += coeffAe_[posE] * uStar_.getValue(posE);
    }
    if (isCoeffExists(numUn)) {
        size_t posN = numUn - 1;
        nbSum += coeffAn_[posN] * uStar_.getValue(posN);
    }
    if (isCoeffExists(numUs)) {
        size_t posS = numUs - 1;
        nbSum += coeffAs_[posS] * uStar_.getValue(posS);
    }
    
    size_t posP = numUp - 1;
    residual_ = std::abs(nbSum + data_.get_b(posP) 
                        - (coeffAp_[posP] * uStar_.getValue(posP)));
    
    return residual_;
}

bool ResidualsCalculatorU::isCoeffExists(const size_t num) {
    if (0 == num) {
        return false;
    }
    else {
        return true;
    }
}

}   