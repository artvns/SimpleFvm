#include "AdjCellInteriorNumsUStore.h"

namespace datastores {

AdjCellInteriorNumsUStore::AdjCellInteriorNumsUStore() {

}

void AdjCellInteriorNumsUStore::createArrays(size_t size) {
    numPw_.create(size);
    numPp_.create(size);
}

ArrayAdt<size_t>& AdjCellInteriorNumsUStore::get_numPw() {
    return numPw_;
}

ArrayAdt<size_t>& AdjCellInteriorNumsUStore::get_numPp() {
    return numPp_;
}

}