#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_ADJACENTCELLSTYPE_ADJCELLSTYPEMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_ADJACENTCELLSTYPE_ADJCELLSTYPEMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/AdjCellsTypeStores/AdjCellsTypeStore.h"


namespace meshloader {
class AdjCellsTypeMask {
private:
    using RecievedDataStore = datastores::AdjCellsTypeStore;
    using AdjCellType = datastores::EnumAdjacentCellTypes;

public:
    AdjCellsTypeMask(RecievedDataStore& store);

    void createStore(size_t size);
    void setCellTypeAsInterior(size_t index);
    void setCellTypeAsBcReal(size_t index);
    void setCellTypeAsBcGhost(size_t index);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_ADJACENTCELLSTYPE_ADJCELLSTYPEMASK_H