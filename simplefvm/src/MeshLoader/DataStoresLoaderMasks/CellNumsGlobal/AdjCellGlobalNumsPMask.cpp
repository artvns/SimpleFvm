#include "AdjCellGlobalNumsPMask.h"

namespace meshloader {


AdjCellGlobalNumsPMask::AdjCellGlobalNumsPMask(
                    RecievedDataStore& store) : store_(store) {

}

void AdjCellGlobalNumsPMask::createStore(size_t size) {
    store_.createArrays(size);
}

void AdjCellGlobalNumsPMask::set_numUStarW(size_t index, size_t value) {
    store_.get_numUStarW().setValue(index, value);
}

void AdjCellGlobalNumsPMask::set_numUStarE(size_t index, size_t value) {
    store_.get_numUStarE().setValue(index, value);
}

void AdjCellGlobalNumsPMask::set_numVStarN(size_t index, size_t value) {
    store_.get_numVStarN().setValue(index, value);
}

void AdjCellGlobalNumsPMask::set_numVStarS(size_t index, size_t value) {
    store_.get_numVStarS().setValue(index, value);
}

}