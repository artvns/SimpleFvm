#include "AdjCellInteriorNumsVMask.h"

namespace meshloader {

AdjCellInteriorNumsVMask::AdjCellInteriorNumsVMask(
            RecievedDataStore& store) : store_(store) {

}

void AdjCellInteriorNumsVMask::createStore(size_t size) {
    store_.createArrays(size);
}

void AdjCellInteriorNumsVMask::set_numPp(size_t index, size_t value) {
    store_.get_numPp().setValue(index, value);
}

void AdjCellInteriorNumsVMask::set_numPs(size_t index, size_t value) {
    store_.get_numPs().setValue(index, value);
}

}