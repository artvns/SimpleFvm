#include "DiffusionSets.h"

namespace fvmsolver {

DiffusionSets::DiffusionSets(
                DataManager& dataManager,
                MeshInfoManager& meshInfoManager) : 
                                dataPorts_(dataManager),
                                setsMakerU_(meshInfoManager),
                                setsMakerV_(meshInfoManager) {

}

DiffusionSets::shPtrMapAbstDiffusion DiffusionSets::createSetForU() {
    return setsMakerU_.createSetForU(dataPorts_);
}

DiffusionSets::shPtrMapAbstDiffusion DiffusionSets::createSetForV() {
    return setsMakerV_.createSetForV(dataPorts_);
}

}