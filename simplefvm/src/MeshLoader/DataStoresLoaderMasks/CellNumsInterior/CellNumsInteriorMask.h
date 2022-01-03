#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_CELLNUMSINTERIORMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_CELLNUMSINTERIORMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/CellNumsInteriorStores/CellNumsInteriorStore.h"


namespace meshloader {

class CellNumsInteriorMask {
private:
    using RecievedDataStore = datastores::CellNumsInteriorStore;

public:
    CellNumsInteriorMask(RecievedDataStore& store);

    void createStore(size_t size);
    
    void setCellNumP(size_t index, size_t value);
    void setCellNumW(size_t index, size_t value);
    void setCellNumE(size_t index, size_t value);
    void setCellNumN(size_t index, size_t value);
    void setCellNumS(size_t index, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_CELLNUMSINTERIOR_CELLNUMSINTERIORMASK_H