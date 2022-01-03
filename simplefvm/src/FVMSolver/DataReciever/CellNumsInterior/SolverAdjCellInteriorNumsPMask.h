#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSPMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSPMASK_H

#include <cstddef>

#include "DataStores/CellNumsInteriorStores/AdjCellInteriorNumsPStore.h"


namespace fvmsolver {

class SolverAdjCellInteriorNumsPMask {
private:
    using RecievedDataStore = datastores::AdjCellInteriorNumsPStore;

public:
    SolverAdjCellInteriorNumsPMask(RecievedDataStore& store);

    size_t get_numUStarW(size_t index) const;
    size_t get_numUStarE(size_t index) const;
    size_t get_numVStarN(size_t index) const;
    size_t get_numVStarS(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSPMASK_H