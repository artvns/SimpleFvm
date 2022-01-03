#ifndef SIMPLEFVM_DATASTORES_CELLNUMSGLOBALSTORES_CELLGLOBALNUMSSTORE_H
#define SIMPLEFVM_DATASTORES_CELLNUMSGLOBALSTORES_CELLGLOBALNUMSSTORE_H

/*
**  Contains the numbers of the current cells for which the calculation is performed.
*/

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class CellNumsGlobalStore {
public:
    CellNumsGlobalStore();
    
    void createArrays(size_t size);

    ArrayAdt<size_t>& get_pCellNum();
    ArrayAdt<size_t>& get_wCellNum();
    ArrayAdt<size_t>& get_eCellNum();
    ArrayAdt<size_t>& get_nCellNum();
    ArrayAdt<size_t>& get_sCellNum();

private:
    ArrayAdt<size_t> cellNumP_;
    ArrayAdt<size_t> cellNumW_;
    ArrayAdt<size_t> cellNumE_;
    ArrayAdt<size_t> cellNumN_;
    ArrayAdt<size_t> cellNumS_;
};

}
#endif // SIMPLEFVM_DATASTORES_CELLNUMSGLOBALSTORES_CELLGLOBALNUMSSTORE_H