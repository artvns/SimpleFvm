#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_STATEFLAGS_STATEFLAGSMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_STATEFLAGS_STATEFLAGSMASK_H

#include "DataStores/StateFlags/SolverStateFlagsStore.cpp"


namespace meshloader {

class StateFlagsMask {
private:
    using RecievedDataStore = datastores::SolverStateFlagsStore;

public:
    StateFlagsMask(RecievedDataStore& store);

    void switchMeshLoadingFlagStarted();
    void switchMeshLoadingFlagAsCompleted();

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_STATEFLAGS_STATEFLAGSMASK_H