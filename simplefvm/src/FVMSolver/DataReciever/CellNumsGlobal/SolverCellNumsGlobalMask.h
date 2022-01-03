#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERCELLGLOBALNUMSMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERCELLGLOBALNUMSMASK_H

#include <cstddef>

#include "DataStores/CellNumsGlobalStores/CellNumsGlobalStore.h"


namespace fvmsolver {

class SolverCellNumsGlobalMask {
private:
    using RecievedDataStore = datastores::CellNumsGlobalStore;

public:
    SolverCellNumsGlobalMask(RecievedDataStore& store);

    size_t get_pCellNum(size_t index) const;
    size_t get_wCellNum(size_t index) const;
    size_t get_eCellNum(size_t index) const;
    size_t get_nCellNum(size_t index) const;
    size_t get_sCellNum(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERCELLGLOBALNUMSMASK_H