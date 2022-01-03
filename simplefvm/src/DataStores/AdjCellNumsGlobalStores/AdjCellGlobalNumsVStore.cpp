#include "AdjCellGlobalNumsVStore.h"

namespace datastores {

AdjCellGlobalNumsVStore::AdjCellGlobalNumsVStore() {

}

void AdjCellGlobalNumsVStore::createArrays(size_t size) {
    numVw_.create(size);
    numVe_.create(size);
    numVn_.create(size);
    numVs_.create(size);

    numUwn_.create(size);
    numUws_.create(size);
    numUen_.create(size);
    numUes_.create(size);

    numPp_.create(size);
    numPs_.create(size);
}


ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumVw() {
    return numVw_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumVe() {
    return numVe_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumVn() {
    return numVn_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumVs() {
    return numVs_;
}


ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumUwn() {
    return numUwn_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumUws() {
    return numUws_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumUen() {
    return numUen_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumUes() {
    return numUes_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumPp() {
    return numPp_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsVStore::getNumPs() {
    return numPs_;
}

}