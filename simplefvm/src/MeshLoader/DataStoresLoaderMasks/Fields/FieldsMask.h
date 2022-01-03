#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_FIELDS_FIELDSMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_FIELDS_FIELDSMASK_H

#include <cstddef>
#include <string>
 
#include "DataStores/FieldsStores/FieldsStore.h"


namespace meshloader {

class FieldsMask {
private:
    using RecievedDataStore = datastores::FieldsStore;

public:
    FieldsMask(RecievedDataStore& store);

    void createStore(size_t uSize, size_t vSize, size_t pSize);

    void setU(size_t index, double value);
    void setV(size_t index, double value);
    void setP(size_t index, double value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_FIELDS_FIELDSMASK_H