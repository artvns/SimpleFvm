#include "CellNumsGlobalMask.h"

namespace meshloader {

CellNumsGlobalMask::CellNumsGlobalMask(
        RecievedDataStore& store) : store_(store) {

}

void CellNumsGlobalMask::createStore(size_t size) {
    store_.createArrays(size);
}

void CellNumsGlobalMask::set_pCellNum(size_t index, size_t value) {
    store_.get_pCellNum().setValue(index, value);
}

void CellNumsGlobalMask::set_wCellNum(size_t index, size_t value) {
    store_.get_wCellNum().setValue(index, value);
}

void CellNumsGlobalMask::set_eCellNum(size_t index, size_t value) {
    store_.get_eCellNum().setValue(index, value);
}

void CellNumsGlobalMask::set_nCellNum(size_t index, size_t value) {
    store_.get_nCellNum().setValue(index, value);
}

void CellNumsGlobalMask::set_sCellNum(size_t index, size_t value) {
    store_.get_sCellNum().setValue(index, value);
}

}