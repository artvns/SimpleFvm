#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSUMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSUMASK_H

#include <cstddef>

#include "DataStores/CellNumsInteriorStores/AdjCellInteriorNumsUStore.h"


namespace fvmsolver {

class SolverAdjCellInteriorNumsUMask {
private:
    using RecievedDataStore = datastores::AdjCellInteriorNumsUStore;

public:
    SolverAdjCellInteriorNumsUMask(RecievedDataStore& store);

    size_t get_numPp(size_t index) const;
    size_t get_numPw(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSUMASK_H