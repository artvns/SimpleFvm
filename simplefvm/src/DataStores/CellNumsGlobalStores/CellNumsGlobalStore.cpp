#include "CellNumsGlobalStore.h"

namespace datastores {

CellNumsGlobalStore::CellNumsGlobalStore() {

}

void CellNumsGlobalStore::createArrays(size_t size) {
    cellNumP_.create(size);
    cellNumW_.create(size);
    cellNumE_.create(size);
    cellNumN_.create(size);
    cellNumS_.create(size);
}

ArrayAdt<size_t>& CellNumsGlobalStore::get_pCellNum() {
    return cellNumP_;
}

ArrayAdt<size_t>& CellNumsGlobalStore::get_wCellNum() {
    return cellNumW_;
}

ArrayAdt<size_t>& CellNumsGlobalStore::get_eCellNum() {
    return cellNumE_;
}

ArrayAdt<size_t>& CellNumsGlobalStore::get_nCellNum() {
    return cellNumN_;
}

ArrayAdt<size_t>& CellNumsGlobalStore::get_sCellNum() {
    return cellNumS_;
}

}