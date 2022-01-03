#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSVMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSVMASK_H

#include <cstddef>
#include <string>

#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsVStore.h"


namespace meshloader {

class AdjCellGlobalNumsVMask {
private:
    using RecievedDataStore = datastores::AdjCellGlobalNumsVStore;

public:
    AdjCellGlobalNumsVMask(RecievedDataStore& store);

    void createStore(size_t size);

    void setNumVn(size_t index, size_t value);
    void setNumVs(size_t index, size_t value);

    void setNumUwn(size_t index, size_t value);
    void setNumUws(size_t index, size_t value);
    void setNumUen(size_t index, size_t value);
    void setNumUes(size_t index, size_t value);
    
    void setNumPp(size_t index, size_t value);
    void setNumPs(size_t index, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSVMASK_H