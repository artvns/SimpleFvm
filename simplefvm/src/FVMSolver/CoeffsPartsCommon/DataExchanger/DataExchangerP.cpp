#include "DataExchangerP.h"

namespace fvmsolver {

DataExchangerP::DataExchangerP(uPtrDataPort spData) :
                                    spData_(std::move(spData)),
                                    data_(*spData_) {

}

void DataExchangerP::assignCurrentCellValues(size_t step) {
    size_t numUw_ = data_.getNumUStarW(step) - 1;
    size_t numUe_ = data_.getNumUStarE(step) - 1;
    size_t numVn_ = data_.getNumVStarN(step) - 1;
    size_t numVs_ = data_.getNumVStarS(step) - 1;

    dw_var_ = data_.get_deU(numUw_);
    de_var_ = data_.get_deU(numUe_);
    dn_var_ = data_.get_deV(numVn_);
    ds_var_ = data_.get_deV(numVs_);
}

}