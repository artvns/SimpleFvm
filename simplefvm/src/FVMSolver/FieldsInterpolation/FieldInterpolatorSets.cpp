#include "FieldInterpolatorSets.h"

namespace fvmsolver {

FieldInterpolatorSets::FieldInterpolatorSets(
                    DataManager& dataManager,
                    MeshInfoManager& meshInfoManager) : 
                            dataPorts_(dataManager),
                            setsMakerU_(meshInfoManager),
                            setsMakerV_(meshInfoManager) {

}

FieldInterpolatorSets::shPtrMapIFieldInterpolator FieldInterpolatorSets::createSetForU() {
    return setsMakerU_.createSetForU(dataPorts_);
}

FieldInterpolatorSets::shPtrMapIFieldInterpolator FieldInterpolatorSets::createSetForV() {
    return setsMakerV_.createSetForV(dataPorts_);
}

}