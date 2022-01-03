#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSPMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSPMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsPStore.h"


namespace meshloader {

class AdjCellGlobalNumsPMask {
private:
    using RecievedDataStore = datastores::AdjCellGlobalNumsPStore;

public:
    AdjCellGlobalNumsPMask(RecievedDataStore& store);

    void createStore(size_t size);

    void set_numUStarW(size_t index, size_t value);
    void set_numUStarE(size_t index, size_t value);
    void set_numVStarN(size_t index, size_t value);
    void set_numVStarS(size_t index, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSPMASK_H