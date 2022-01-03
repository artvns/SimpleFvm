#include "FieldsStore.h"

namespace datastores {

FieldsStore::FieldsStore() {

}

void FieldsStore::createArrays(size_t uCells, size_t vCells, size_t pCells) {
    u_.create(uCells);
    v_.create(vCells);
    p_.create(pCells);

    uCellCentered_.create(pCells);
    vCellCentered_.create(pCells);
}

ArrayAdt<double>& FieldsStore::get_u() {
    return u_;
}

ArrayAdt<double>& FieldsStore::get_v() {
    return v_;
}

ArrayAdt<double>& FieldsStore::get_p() {
    return p_;
}


ArrayAdt<double>& FieldsStore::get_uCellCentered() {
    return uCellCentered_;
}

ArrayAdt<double>& FieldsStore::get_vCellCentered() {
    return vCellCentered_;
}

}