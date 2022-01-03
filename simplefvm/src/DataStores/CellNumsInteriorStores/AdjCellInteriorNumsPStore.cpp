#include "AdjCellInteriorNumsPStore.h"

namespace datastores {

AdjCellInteriorNumsPStore::AdjCellInteriorNumsPStore() {

}

void AdjCellInteriorNumsPStore::createArrays(size_t size) {
    numUStarW_.create(size);
    numUStarE_.create(size);
    numVStarN_.create(size);
    numVStarS_.create(size);
}


ArrayAdt<size_t>& AdjCellInteriorNumsPStore::get_numUStarW() {
    return numUStarW_;
}

ArrayAdt<size_t>& AdjCellInteriorNumsPStore::get_numUStarE() {
    return numUStarE_;
}

ArrayAdt<size_t>& AdjCellInteriorNumsPStore::get_numVStarN() {
    return numVStarN_;
}

ArrayAdt<size_t>& AdjCellInteriorNumsPStore::get_numVStarS() {
    return numVStarS_;
}

}