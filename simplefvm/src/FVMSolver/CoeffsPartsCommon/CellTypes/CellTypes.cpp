#include "CellTypes.h"

namespace fvmsolver {

CellTypes::CellTypes(uPtrDataPort spData) :
                            spData_(std::move(spData)),
                            data_(*spData_) {

}

void CellTypes::assignCurrentCellValues(size_t step) {
    size_t posW_ = data_.get_wNum(step) - 1;
    size_t posE_ = data_.get_eNum(step) - 1;
    size_t posN_ = data_.get_nNum(step) - 1;
    size_t posS_ = data_.get_sNum(step) - 1;

    wType_ = data_.getType(posW_);
    eType_ = data_.getType(posE_);
    nType_ = data_.getType(posN_);
    sType_ = data_.getType(posS_);
}

EnumAdjacentCellTypes CellTypes::get_wType() {
    return wType_;
}

EnumAdjacentCellTypes CellTypes::get_eType() {
    return eType_;
}

EnumAdjacentCellTypes CellTypes::get_nType() {
    return nType_;
}

EnumAdjacentCellTypes CellTypes::get_sType() {
    return sType_;
}

}