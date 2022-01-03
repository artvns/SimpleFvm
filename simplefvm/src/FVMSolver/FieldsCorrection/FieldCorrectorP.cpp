#include "FieldCorrectorP.h"

namespace fvmsolver {

FieldCorrectorP::FieldCorrectorP(uPtrDataPort spData) :
                                        spData_(std::move(spData)),
                                        data_(*spData_),
                                        pPrime_(spData_->getPPrime_()) {

}

void FieldCorrectorP::correct(size_t step) {
    size_t numGlobPp = data_.getGlobNumPp(step) - 1;
    size_t numInterPp = data_.getInterNumPp(step) - 1;

    double pCorrected = data_.get_p(numGlobPp) +
                            relaxFactor_ * pPrime_.getValue(numInterPp);

    data_.set_p(numGlobPp, pCorrected);
}

}