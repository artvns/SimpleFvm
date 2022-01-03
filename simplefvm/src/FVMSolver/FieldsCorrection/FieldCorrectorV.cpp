#include "FieldCorrectorV.h"

namespace fvmsolver {

FieldCorrectorV::FieldCorrectorV(uPtrDataPort spData) :
                                        spData_(std::move(spData)),
                                        data_(*spData_),
                                        vStar_(spData_->getVStar()),
                                        pPrime_(spData_->getPPrime()) {

}

void FieldCorrectorV::correct(size_t step) {
    size_t numGlobVp = data_.getGlobNumVp(step) - 1;
    size_t numInterVp = data_.getInterNumVp(step) - 1;

    size_t numInterPp = data_.getInterNumPn(step) - 1;
    size_t numInterPn = data_.getInterNumPp(step) - 1;

    double vCorrected = vStar_.getValue(numInterVp) + 
                            relaxFactor_ * data_.get_deV(numInterVp) *
                                (pPrime_.getValue(numInterPp) - 
                                    pPrime_.getValue(numInterPn));

    data_.set_v(numGlobVp, vCorrected);
}

}