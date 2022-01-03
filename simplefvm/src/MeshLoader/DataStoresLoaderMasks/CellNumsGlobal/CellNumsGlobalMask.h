#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_CELLGLOBALNUMSMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_CELLGLOBALNUMSMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/CellNumsGlobalStores/CellNumsGlobalStore.h"


namespace meshloader {

class CellNumsGlobalMask {
private:
    using RecievedDataStore = datastores::CellNumsGlobalStore;

public:
    CellNumsGlobalMask(RecievedDataStore& store);

    void createStore(size_t size);

    void set_pCellNum(size_t index, size_t value);
    void set_wCellNum(size_t index, size_t value);
    void set_eCellNum(size_t index, size_t value);
    void set_nCellNum(size_t index, size_t value);
    void set_sCellNum(size_t index, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_CELLGLOBALNUMSMASK_H