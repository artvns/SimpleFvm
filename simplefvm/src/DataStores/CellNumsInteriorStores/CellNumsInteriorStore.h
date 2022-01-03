#ifndef SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_CELLNUMSINTERIORSTORE_H
#define SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_CELLNUMSINTERIORSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class CellNumsInteriorStore {
public:
    CellNumsInteriorStore();
    
    void createArrays(size_t size);

    ArrayAdt<size_t>& get_CellNumP();
    ArrayAdt<size_t>& get_CellNumW();
    ArrayAdt<size_t>& get_CellNumE();
    ArrayAdt<size_t>& get_CellNumN();
    ArrayAdt<size_t>& get_CellNumS();

private:
    ArrayAdt<size_t> cellNumP_;
    ArrayAdt<size_t> cellNumW_;
    ArrayAdt<size_t> cellNumE_;
    ArrayAdt<size_t> cellNumN_;
    ArrayAdt<size_t> cellNumS_;
};

}
#endif // SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_CELLNUMSINTERIORSTORE_H