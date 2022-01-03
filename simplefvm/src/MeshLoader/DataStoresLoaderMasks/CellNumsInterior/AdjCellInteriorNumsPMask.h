#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSPMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSPMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/CellNumsInteriorStores/AdjCellInteriorNumsPStore.h"


namespace meshloader {

class AdjCellInteriorNumsPMask {
private:
    using RecievedDataStore = datastores::AdjCellInteriorNumsPStore;

public:
    AdjCellInteriorNumsPMask(RecievedDataStore& store);

    void createStore(size_t size);

    void set_numUStarW(size_t index, size_t value);
    void set_numUStarE(size_t index, size_t value);
    void set_numVStarN(size_t index, size_t value);
    void set_numVStarS(size_t index, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSPMASK_H