#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSUMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSUMASK_H

#include <cstddef>

#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsUStore.h"


namespace fvmsolver {

class SolverAdjCellGlobalNumsUMask {
private:
    using RecievedDataStore = datastores::AdjCellGlobalNumsUStore;

public:
    SolverAdjCellGlobalNumsUMask(RecievedDataStore& store);

    size_t getNumUw(size_t index) const;
    size_t getNumUe(size_t index) const;

    size_t getNumVnw(size_t index) const;
    size_t getNumVne(size_t index) const;
    size_t getNumVsw(size_t index) const;
    size_t getNumVse(size_t index) const;

    size_t getNumPp(size_t index) const;
    size_t getNumPw(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_CELLNUMSGLOBAL_SOLVERADJCELLGLOBALNUMSUMASK_H