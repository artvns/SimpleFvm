#ifndef SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSUSTORE_H
#define SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSUSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class AdjCellInteriorNumsUStore {
public:
    AdjCellInteriorNumsUStore();

    void createArrays(size_t size);

    ArrayAdt<size_t>& get_numPw();
    ArrayAdt<size_t>& get_numPp();

private:
    ArrayAdt<size_t> numPw_;
    ArrayAdt<size_t> numPp_;
};

}
#endif // SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSUSTORE_H