#include "AdjCellInteriorNumsPMask.h"

namespace meshloader {

AdjCellInteriorNumsPMask::AdjCellInteriorNumsPMask(
                RecievedDataStore& store) : store_(store) {

}

void AdjCellInteriorNumsPMask::createStore(size_t size) {
    store_.createArrays(size);
}

void AdjCellInteriorNumsPMask::set_numUStarW(size_t index, size_t value) {
    store_.get_numUStarW().setValue(index, value);
}

void AdjCellInteriorNumsPMask::set_numUStarE(size_t index, size_t value) {
    store_.get_numUStarE().setValue(index, value);
}

void AdjCellInteriorNumsPMask::set_numVStarN(size_t index, size_t value) {
    store_.get_numVStarN().setValue(index, value);
}

void AdjCellInteriorNumsPMask::set_numVStarS(size_t index, size_t value) {
    store_.get_numVStarS().setValue(index, value);
}

}