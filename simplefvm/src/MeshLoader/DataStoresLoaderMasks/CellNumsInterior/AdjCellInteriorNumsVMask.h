#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSVMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSVMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/CellNumsInteriorStores/AdjCellInteriorNumsVStore.h"


namespace meshloader {

class AdjCellInteriorNumsVMask {
private:
    using RecievedDataStore = datastores::AdjCellInteriorNumsVStore;

public:
    AdjCellInteriorNumsVMask(RecievedDataStore& store);

    void createStore(size_t size);

    void set_numPp(size_t index, size_t value);
    void set_numPs(size_t index, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSVMASK_H