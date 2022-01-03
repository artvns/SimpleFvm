#include "CellNumbers.h"

namespace fvmsolver {

CellNumbers::CellNumbers(uPtrDataPort spData) :
                                spData_(std::move(spData)),
                                data_(*spData_) {

}

void CellNumbers::assignCurrentCellValues(size_t step) {
    wNum_ = data_.get_wNum(step);
    eNum_ = data_.get_eNum(step);
    nNum_ = data_.get_nNum(step);
    sNum_ = data_.get_sNum(step);
    pNum_ = data_.get_pNum(step);
}

size_t CellNumbers::get_wNum() {
    return wNum_;
}

size_t CellNumbers::get_eNum() {
    return eNum_;
}

size_t CellNumbers::get_nNum() {
    return nNum_;
}

size_t CellNumbers::get_sNum() {
    return sNum_;
}

size_t CellNumbers::get_pNum() {
    return pNum_;
}

}