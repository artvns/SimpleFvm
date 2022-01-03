#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSVMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSVMASK_H

#include <cstddef>

#include "DataStores/CellNumsInteriorStores/AdjCellInteriorNumsVStore.h"


namespace fvmsolver {

class SolverAdjCellInteriorNumsVMask {
private:
    using RecievedDataStore = datastores::AdjCellInteriorNumsVStore;

public:
    SolverAdjCellInteriorNumsVMask(RecievedDataStore& store);

    size_t get_numPp(size_t index) const;
    size_t get_numPs(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSINTERIOR_SOLVERADJCELLINTERIORNUMSVMASK_H