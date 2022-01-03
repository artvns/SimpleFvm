#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSUMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSUMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsUStore.h"


namespace meshloader {

class AdjCellGlobalNumsUMask {
private:
    using RecievedDataStore = datastores::AdjCellGlobalNumsUStore;

public:
    AdjCellGlobalNumsUMask(RecievedDataStore& store);

    void createStore(size_t size);

    void setNumUw(size_t index, size_t value);
    void setNumUe(size_t index, size_t value);

    void setNumVnw(size_t index, size_t value);
    void setNumVne(size_t index, size_t value);
    void setNumVsw(size_t index, size_t value);
    void setNumVse(size_t index, size_t value);
    
    void setNumPp(size_t index, size_t value);
    void setNumPw(size_t index, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSGLOBAL_ADJCELLGLOBALNUMSUMASK_H