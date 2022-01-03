#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSUMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSUMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/CellNumsInteriorStores/AdjCellInteriorNumsUStore.h"


namespace meshloader {

class AdjCellInteriorNumsUMask {
private:
    using RecievedDataStore = datastores::AdjCellInteriorNumsUStore;

public:
    AdjCellInteriorNumsUMask(RecievedDataStore& store);

    void createStore(size_t size);

    void set_numPp(size_t index, size_t value);
    void set_numPw(size_t index, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_ADJCELLINTERIORNUMSUMASK_H