#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_MESHPARAMETERS_MESHPARAMSMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_MESHPARAMETERS_MESHPARAMSMASK_H

#include <cstddef>
#include <string>

#include "DataStores/MeshParametersStores/MeshParametersStore.h"


namespace meshloader {

class MeshParamsMask {
private:
    using RecievedDataStore = datastores::MeshParametersStore;

public:
    MeshParamsMask(RecievedDataStore& store);

    void createStore(size_t size);

    void set_dX(size_t index, double value);
    void set_dY(size_t index, double value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_MESHPARAMETERS_MESHPARAMSMASK_H