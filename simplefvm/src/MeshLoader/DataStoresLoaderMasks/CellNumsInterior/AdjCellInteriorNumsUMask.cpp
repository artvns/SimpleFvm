#include "AdjCellInteriorNumsUMask.h"

namespace meshloader {

AdjCellInteriorNumsUMask::AdjCellInteriorNumsUMask(
                RecievedDataStore& store) : store_(store) {

}

void AdjCellInteriorNumsUMask::createStore(size_t size) {
    store_.createArrays(size);
}

void AdjCellInteriorNumsUMask::set_numPp(size_t index, size_t value) {
    store_.get_numPp().setValue(index, value);
}

void AdjCellInteriorNumsUMask::set_numPw(size_t index, size_t value) {
    store_.get_numPw().setValue(index, value);
}

}