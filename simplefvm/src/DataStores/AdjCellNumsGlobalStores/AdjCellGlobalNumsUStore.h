#ifndef SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSUSTORE_H
#define SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSUSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class AdjCellGlobalNumsUStore {
public:
    AdjCellGlobalNumsUStore();

    void createArrays(size_t size);

    ArrayAdt<size_t>& getNumUw();
    ArrayAdt<size_t>& getNumUe();
    ArrayAdt<size_t>& getNumUn();
    ArrayAdt<size_t>& getNumUs();

    ArrayAdt<size_t>& getNumVnw();
    ArrayAdt<size_t>& getNumVne();
    ArrayAdt<size_t>& getNumVsw();
    ArrayAdt<size_t>& getNumVse();

    ArrayAdt<size_t>& getNumPp();
    ArrayAdt<size_t>& getNumPw();

private:
    ArrayAdt<size_t> numUp_;
    ArrayAdt<size_t> numUw_;
    ArrayAdt<size_t> numUe_;
    ArrayAdt<size_t> numUn_;
    ArrayAdt<size_t> numUs_;

    ArrayAdt<size_t> numVnw_;
    ArrayAdt<size_t> numVne_;
    ArrayAdt<size_t> numVsw_;
    ArrayAdt<size_t> numVse_;

    ArrayAdt<size_t> numPp_;
    ArrayAdt<size_t> numPw_;
};

}
#endif // SIMPLEFVM_DATASTORES_ADJCELLNUMSGLOBALSTORES_ADJCELLGLOBALNUMSUSTORE_H