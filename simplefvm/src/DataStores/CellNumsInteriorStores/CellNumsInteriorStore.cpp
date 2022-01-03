#include "CellNumsInteriorStore.h"

namespace datastores {

CellNumsInteriorStore::CellNumsInteriorStore() {

}

void CellNumsInteriorStore::createArrays(size_t size) {
    cellNumP_.create(size);
    cellNumW_.create(size);
    cellNumE_.create(size);
    cellNumN_.create(size);
    cellNumS_.create(size);
}

ArrayAdt<size_t>& CellNumsInteriorStore::get_CellNumP() {
    return cellNumP_;
}

ArrayAdt<size_t>& CellNumsInteriorStore::get_CellNumW() {
    return cellNumW_;
}

ArrayAdt<size_t>& CellNumsInteriorStore::get_CellNumE() {
    return cellNumE_;
}

ArrayAdt<size_t>& CellNumsInteriorStore::get_CellNumN() {
    return cellNumN_;
}

ArrayAdt<size_t>& CellNumsInteriorStore::get_CellNumS() {
    return cellNumS_;
}

}