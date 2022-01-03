#include "AdjCellGlobalNumsUMask.h"

namespace meshloader {

AdjCellGlobalNumsUMask::AdjCellGlobalNumsUMask(
                RecievedDataStore& store) : store_(store) {
}

void AdjCellGlobalNumsUMask::createStore(size_t size) {
    store_.createArrays(size);
}

void AdjCellGlobalNumsUMask::setNumUw(size_t index, size_t value) {
    store_.getNumUw().setValue(index, value);
}

void AdjCellGlobalNumsUMask::setNumUe(size_t index, size_t value) {
    store_.getNumUe().setValue(index, value);
}

void AdjCellGlobalNumsUMask::setNumVnw(size_t index, size_t value) {
    store_.getNumVnw().setValue(index, value);
}

void AdjCellGlobalNumsUMask::setNumVne(size_t index, size_t value) {
    store_.getNumVne().setValue(index, value);
}

void AdjCellGlobalNumsUMask::setNumVsw(size_t index, size_t value) {
    store_.getNumVsw().setValue(index, value);
}

void AdjCellGlobalNumsUMask::setNumVse(size_t index, size_t value) {
    store_.getNumVse().setValue(index, value);
}
    
void AdjCellGlobalNumsUMask::setNumPp(size_t index, size_t value) {
    store_.getNumVne().setValue(index, value);
}

void AdjCellGlobalNumsUMask::setNumPw(size_t index, size_t value) {
    store_.getNumPw().setValue(index, value);
}

}