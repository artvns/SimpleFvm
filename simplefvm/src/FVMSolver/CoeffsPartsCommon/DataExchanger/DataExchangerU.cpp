#include "DataExchangerU.h"

namespace fvmsolver {

DataExchangerU::DataExchangerU(uPtrDataPort spData) :
                                    spData_(std::move(spData)),
                                    data_(*spData_) {

}

void DataExchangerU::assignCurrentCellValues(size_t step) {
    
}

void DataExchangerU::add_de(size_t step, double a_p) {
    size_t globNumpPos = data_.getGlobNumUp(step) - 1;
    size_t posP_ = data_.get_pNum(step) - 1;

    double dY_var_ = data_.get_dY(globNumpPos);
    double de_ = (dY_var_ * 1.0) / a_p;

    data_.set_de(posP_, de_);
}

}