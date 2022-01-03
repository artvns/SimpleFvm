#ifndef SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSVSTORE_H
#define SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSVSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class AdjCellInteriorNumsVStore {
public:
    AdjCellInteriorNumsVStore();

    void createArrays(size_t size);

    ArrayAdt<size_t>& get_numPp();
    ArrayAdt<size_t>& get_numPs();

private:
    ArrayAdt<size_t> numPp_;
    ArrayAdt<size_t> numPs_;
};

}
#endif // SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSVSTORE_H