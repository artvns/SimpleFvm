#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSPMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSPMASK_H

#include <cstddef>
#include <string>

#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsPStore.h"


namespace fvmsolver {

class SolverAdjCellGlobalNumsPMask {
private:
    using RecievedDataStore = datastores::AdjCellGlobalNumsPStore;
    
public:
    SolverAdjCellGlobalNumsPMask(RecievedDataStore& store);

    size_t get_numUStarW(size_t index) const;
    size_t get_numUStarE(size_t index) const;
    size_t get_numVStarN(size_t index) const;
    size_t get_numVStarS(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSPMASK_H