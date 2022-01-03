#include "StateFlagsMask.h"

namespace meshloader {

StateFlagsMask::StateFlagsMask(
    RecievedDataStore& store) : store_(store) {

}

void StateFlagsMask::switchMeshLoadingFlagStarted() {
    store_.isMeshLoaded = false;
}

void StateFlagsMask::switchMeshLoadingFlagAsCompleted() {
    store_.isMeshLoaded = true;
}

}