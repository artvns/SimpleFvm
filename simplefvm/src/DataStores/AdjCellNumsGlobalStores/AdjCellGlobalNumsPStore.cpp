#include "AdjCellGlobalNumsPStore.h"

namespace datastores {

AdjCellGlobalNumsPStore::AdjCellGlobalNumsPStore() {

}

void AdjCellGlobalNumsPStore::createArrays(size_t size) {
    numPw_.create(size);
    numPe_.create(size);
    numPn_.create(size);
    numPs_.create(size);

    numUStarW_.create(size);
    numUStarE_.create(size);
    numVStarN_.create(size);
    numVStarS_.create(size);
}


ArrayAdt<size_t>& AdjCellGlobalNumsPStore::getNumPw() {
    return numPw_;
}
ArrayAdt<size_t>& AdjCellGlobalNumsPStore::getNumPe() {
    return numPe_;
}
ArrayAdt<size_t>& AdjCellGlobalNumsPStore::getNumPn() {
    return numPn_;
}
ArrayAdt<size_t>& AdjCellGlobalNumsPStore::getNumPs() {
    return numPs_;
}


ArrayAdt<size_t>& AdjCellGlobalNumsPStore::get_numUStarW() {
    return numUStarW_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsPStore::get_numUStarE() {
    return numUStarE_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsPStore::get_numVStarN() {
    return numVStarN_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsPStore::get_numVStarS() {
    return numVStarS_;
}

}