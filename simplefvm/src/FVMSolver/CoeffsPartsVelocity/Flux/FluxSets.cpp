#include "FluxSets.h"

namespace fvmsolver {

FluxSets::FluxSets(
                DataManager& dataManager,
                MeshInfoManager& meshInfoManager) : 
                                dataPorts_(dataManager),
                                setsMakerU_(meshInfoManager),
                                setsMakerV_(meshInfoManager) {

}

FluxSets::shPtrMapAbstFlux FluxSets::createSetForU() {
    return setsMakerU_.createSetForU(dataPorts_);
}

FluxSets::shPtrMapAbstFlux FluxSets::createSetForV() {
    return setsMakerV_.createSetForV(dataPorts_);
}

}