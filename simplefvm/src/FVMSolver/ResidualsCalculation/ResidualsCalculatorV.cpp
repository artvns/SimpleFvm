#include "ResidualsCalculatorV.h"

namespace fvmsolver {

ResidualsCalculatorV::ResidualsCalculatorV(
                        uPtrDataPort spData) :
                                spData_(std::move(spData)),
                                data_(*spData_),
                                vStar_(spData_->getVStar()),
                                coeffAp_(spData_->getAp()),
                                coeffAw_(spData_->getAw()),
                                coeffAe_(spData_->getAe()),
                                coeffAn_(spData_->getAn()),
                                coeffAs_(spData_->getAs()) {

}

double ResidualsCalculatorV::calculateCellResidual(const size_t step) {
    size_t numVp = data_.getInterNumVp(step);
    size_t numVw = data_.getInterNumVw(step);
    size_t numVe = data_.getInterNumVe(step);
    size_t numVn = data_.getInterNumVn(step);
    size_t numVs = data_.getInterNumVs(step);

    double nbSum = 0.0;

    if (isCoeffExists(numVw)) {
        size_t posW = numVw - 1;
        nbSum += coeffAw_[posW] * vStar_.getValue(posW);
    }
    if (isCoeffExists(numVe)) {
        size_t posE = numVe - 1;
        nbSum += coeffAe_[posE] * vStar_.getValue(posE);
    }
    if (isCoeffExists(numVn)) {
        size_t posN = numVn - 1;
        nbSum += coeffAn_[posN] * vStar_.getValue(posN);
    }
    if (isCoeffExists(numVs)) {
        size_t posS = numVs - 1;
        nbSum += coeffAs_[posS] * vStar_.getValue(posS);
    }               

    size_t posP = numVp - 1;
    residual_ = std::abs(nbSum + data_.get_b(posP) 
                        - (coeffAp_[posP] * vStar_.getValue(posP)));
    
    return residual_;
}

bool ResidualsCalculatorV::isCoeffExists(const size_t num) {
    if (0 == num) {
        return false;
    }
    else {
        return true;
    }
}

}