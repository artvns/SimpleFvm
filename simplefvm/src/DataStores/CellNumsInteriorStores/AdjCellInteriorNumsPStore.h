#ifndef SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSPSTORE_H
#define SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSPSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class AdjCellInteriorNumsPStore {
public:
    AdjCellInteriorNumsPStore();

    void createArrays(size_t size);

    ArrayAdt<size_t>& get_numUStarW();
    ArrayAdt<size_t>& get_numUStarE();
    ArrayAdt<size_t>& get_numVStarN();
    ArrayAdt<size_t>& get_numVStarS();

private:
    ArrayAdt<size_t> numUStarW_;
    ArrayAdt<size_t> numUStarE_;
    ArrayAdt<size_t> numVStarN_;
    ArrayAdt<size_t> numVStarS_;
};

}
#endif // SIMPLEFVM_DATASTORES_CELLNUMSINTERIORSTORES_ADJCELLINTERIORNUMSPSTORE_H