#include "CellNumsInteriorMask.h"

namespace meshloader {

CellNumsInteriorMask::CellNumsInteriorMask(
        RecievedDataStore& store) : store_(store) {
}

void CellNumsInteriorMask::createStore(size_t size) {
    store_.createArrays(size);
}

void CellNumsInteriorMask::setCellNumP(size_t index, size_t value) {
    store_.get_CellNumP().setValue(index, value);
}

void CellNumsInteriorMask::setCellNumW(size_t index, size_t value) {
    store_.get_CellNumW().setValue(index, value);
}

void CellNumsInteriorMask::setCellNumE(size_t index, size_t value) {
    store_.get_CellNumE().setValue(index, value);
}

void CellNumsInteriorMask::setCellNumN(size_t index, size_t value) {
    store_.get_CellNumN().setValue(index, value);
}

void CellNumsInteriorMask::setCellNumS(size_t index, size_t value) {
    store_.get_CellNumS().setValue(index, value);
}

}