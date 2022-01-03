#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_ADJACENTCELLSTYPE_SOLVERADJCELLSTYPEMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_ADJACENTCELLSTYPE_SOLVERADJCELLSTYPEMASK_H

#include <cstddef>

#include "FVMSolver/Tools/Enums/EnumAdjacentCellTypes.cpp"
#include "DataStores/AdjCellsTypeStores/AdjCellsTypeStore.h"


namespace fvmsolver {

class SolverAdjCellsTypeMask {
private:
    using RecievedDataStore = datastores::AdjCellsTypeStore;

public:
    SolverAdjCellsTypeMask(RecievedDataStore& store);

    EnumAdjacentCellTypes getCellType(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_ADJACENTCELLSTYPE_SOLVERADJCELLSTYPEMASK_H