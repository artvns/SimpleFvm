#ifndef SIMPLEFVM_DATASTORES_FIELDSSTORES_FIELDSSTORE_H
#define SIMPLEFVM_DATASTORES_FIELDSSTORES_FIELDSSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class FieldsStore {
public:
    FieldsStore();

    void createArrays(size_t uCells, size_t vCells, size_t pCells);

    ArrayAdt<double>& get_u();
    ArrayAdt<double>& get_v();
    ArrayAdt<double>& get_p();

    ArrayAdt<double>& get_uCellCentered();
    ArrayAdt<double>& get_vCellCentered();

private:
    ArrayAdt<double> u_;
    ArrayAdt<double> v_;
    ArrayAdt<double> p_;

    ArrayAdt<double> uCellCentered_;
    ArrayAdt<double> vCellCentered_;
};

}
#endif // SIMPLEFVM_DATASTORES_FIELDSSTORES_FIELDSSTORE_H