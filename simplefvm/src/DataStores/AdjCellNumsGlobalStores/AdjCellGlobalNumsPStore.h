#ifndef SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSPSTORE_H
#define SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSPSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class AdjCellGlobalNumsPStore {
public:
    AdjCellGlobalNumsPStore();

    void createArrays(size_t size);

    ArrayAdt<size_t>& getNumPw();
    ArrayAdt<size_t>& getNumPe();
    ArrayAdt<size_t>& getNumPn();
    ArrayAdt<size_t>& getNumPs();

    ArrayAdt<size_t>& get_numUStarW();
    ArrayAdt<size_t>& get_numUStarE();
    ArrayAdt<size_t>& get_numVStarN();
    ArrayAdt<size_t>& get_numVStarS();

private:
    ArrayAdt<size_t> numPw_;
    ArrayAdt<size_t> numPe_;
    ArrayAdt<size_t> numPn_;
    ArrayAdt<size_t> numPs_;

    ArrayAdt<size_t> numUStarW_;
    ArrayAdt<size_t> numUStarE_;
    ArrayAdt<size_t> numVStarN_;
    ArrayAdt<size_t> numVStarS_;
};

}
#endif // SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSPSTORE_H