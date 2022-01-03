#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSVMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSVMASK_H

#include <cstddef>

#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsVStore.h"


namespace fvmsolver {

class SolverAdjCellGlobalNumsVMask {
private:
    using RecievedDataStore = datastores::AdjCellGlobalNumsVStore;

public:
    SolverAdjCellGlobalNumsVMask(RecievedDataStore& store);

    size_t getNumVn(size_t index) const;
    size_t getNumVs(size_t index) const;

    size_t getNumUwn(size_t index) const;
    size_t getNumUws(size_t index) const;
    size_t getNumUen(size_t index) const;
    size_t getNumUes(size_t index) const;
    
    size_t getNumPp(size_t index) const;
    size_t getNumPs(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSVMASK_H