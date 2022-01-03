#include "DataExchangerV.h"

namespace fvmsolver {

DataExchangerV::DataExchangerV(uPtrDataPort spData) :
                                    spData_(std::move(spData)),
                                    data_(*spData_) {

}

void DataExchangerV::assignCurrentCellValues(size_t step) {
    
}

void DataExchangerV::add_de(size_t step, double a_p) {
    size_t globNumpPos = data_.getGlobNumVp(step) - 1;
    size_t posP_ = data_.get_pNum(step) - 1;

    double dX_var_ = data_.get_dX(globNumpPos);
    double de_ = (dX_var_ * 1.0) / a_p;

    data_.set_de(posP_, de_);
}

}