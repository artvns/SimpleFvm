#include "FieldCorrectorU.h"

namespace fvmsolver {

FieldCorrectorU::FieldCorrectorU(uPtrDataPort spData) :
                                        spData_(std::move(spData)),
                                        data_(*spData_),
                                        uStar_(spData_->getUStar()),
                                        pPrime_(spData_->getPPrime()) {

}


void FieldCorrectorU::correct(size_t step) {
    size_t numGlobUp = data_.getGlobNumUp(step) - 1;
    size_t numInterUp = data_.getInterNumUp(step) - 1;

    size_t numInterPp = data_.getInterNumPp(step) - 1;
    size_t numInterPe = data_.getInterNumPe(step) - 1;

    double uCorrected = uStar_.getValue(numInterUp) + 
                            relaxFactor_ * data_.get_deU(numInterUp) *
                                (pPrime_.getValue(numInterPp) - 
                                    pPrime_.getValue(numInterPe));

    data_.set_u(numGlobUp, uCorrected);
}

}