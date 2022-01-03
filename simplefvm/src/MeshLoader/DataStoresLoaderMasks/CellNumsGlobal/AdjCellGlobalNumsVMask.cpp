#include "AdjCellGlobalNumsVMask.h"

namespace meshloader {

AdjCellGlobalNumsVMask::AdjCellGlobalNumsVMask(
            RecievedDataStore& store) : store_(store) {

}

void AdjCellGlobalNumsVMask::createStore(size_t size) {
    store_.createArrays(size);
}

void AdjCellGlobalNumsVMask::setNumVn(size_t index, size_t value) {
    store_.getNumVn().setValue(index, value);
}

void AdjCellGlobalNumsVMask::setNumVs(size_t index, size_t value) {
    store_.getNumVs().setValue(index, value);
}

void AdjCellGlobalNumsVMask::setNumUwn(size_t index, size_t value) {
    store_.getNumUwn().setValue(index, value);
}

void AdjCellGlobalNumsVMask::setNumUws(size_t index, size_t value) {
    store_.getNumUws().setValue(index, value);
}

void AdjCellGlobalNumsVMask::setNumUen(size_t index, size_t value) {
    store_.getNumUen().setValue(index, value);
}

void AdjCellGlobalNumsVMask::setNumUes(size_t index, size_t value) {
    store_.getNumUes().setValue(index, value);
}

void AdjCellGlobalNumsVMask::setNumPp(size_t index, size_t value) {
    store_.getNumPp().setValue(index, value);
}

void AdjCellGlobalNumsVMask::setNumPs(size_t index, size_t value) {
    store_.getNumPs().setValue(index, value);
}

}