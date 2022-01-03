#ifndef SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSVSTORE_H
#define SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSVSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class AdjCellGlobalNumsVStore {
public:
    AdjCellGlobalNumsVStore();

    void createArrays(size_t vCells);

    ArrayAdt<size_t>& getNumVw();
    ArrayAdt<size_t>& getNumVe();
    ArrayAdt<size_t>& getNumVn();
    ArrayAdt<size_t>& getNumVs();

    ArrayAdt<size_t>& getNumUwn();
    ArrayAdt<size_t>& getNumUws();
    ArrayAdt<size_t>& getNumUen();
    ArrayAdt<size_t>& getNumUes();

    ArrayAdt<size_t>& getNumPp();
    ArrayAdt<size_t>& getNumPs();

private:
    ArrayAdt<size_t> numVw_;
    ArrayAdt<size_t> numVe_;
    ArrayAdt<size_t> numVn_;
    ArrayAdt<size_t> numVs_;

    ArrayAdt<size_t> numUwn_;
    ArrayAdt<size_t> numUws_;
    ArrayAdt<size_t> numUen_;
    ArrayAdt<size_t> numUes_;

    ArrayAdt<size_t> numPp_;
    ArrayAdt<size_t> numPs_;
};

}
#endif // SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSVSTORE_H