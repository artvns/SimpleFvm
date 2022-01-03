#include "AdjCellInteriorNumsVStore.h"

namespace datastores {

AdjCellInteriorNumsVStore::AdjCellInteriorNumsVStore() {

}

void AdjCellInteriorNumsVStore::createArrays(size_t size) {
    numPp_.create(size);
    numPs_.create(size);
}

ArrayAdt<size_t>& AdjCellInteriorNumsVStore::get_numPp() {
    return numPp_;
}

ArrayAdt<size_t>& AdjCellInteriorNumsVStore::get_numPs() {
    return numPs_;
}

}