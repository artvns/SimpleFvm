#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERCELLNUMSINTERIORMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERCELLNUMSINTERIORMASK_H

#include <cstddef>

#include "DataStores/CellNumsInteriorStores/CellNumsInteriorStore.h"


namespace fvmsolver {

class SolverCellNumsInteriorMask {
private:
    using RecievedDataStore = datastores::CellNumsInteriorStore;

public:
    SolverCellNumsInteriorMask(RecievedDataStore& store);

    size_t getCellNumP(size_t index) const;
    size_t getCellNumW(size_t index) const;
    size_t getCellNumE(size_t index) const;
    size_t getCellNumN(size_t index) const;
    size_t getCellNumS(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERCELLNUMSINTERIORMASK_H