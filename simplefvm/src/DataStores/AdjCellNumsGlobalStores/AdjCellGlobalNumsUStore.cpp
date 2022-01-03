#include "AdjCellGlobalNumsUStore.h"

namespace datastores {

AdjCellGlobalNumsUStore::AdjCellGlobalNumsUStore() {
  
} 

void AdjCellGlobalNumsUStore::createArrays(size_t size) {
    numUw_.create(size);
    numUe_.create(size);
    numUn_.create(size);
    numUs_.create(size);

    numVnw_.create(size);
    numVne_.create(size);
    numVsw_.create(size);
    numVse_.create(size);

    numPp_.create(size);
    numPw_.create(size);
}


ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumUw() {
    return numUw_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumUe() {
    return numUe_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumUn() {
    return numUn_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumUs() {
    return numUs_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumVnw() {
    return numVnw_;
}


ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumVne() {
    return numVne_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumVsw() {
    return numVsw_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumVse() {
    return numVse_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumPp() {
    return numPp_;
}

ArrayAdt<size_t>& AdjCellGlobalNumsUStore::getNumPw() {
    return numPw_;
}

}