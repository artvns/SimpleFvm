#include "RhsVelocitySets.h"

namespace fvmsolver {

RhsVelocitySets::RhsVelocitySets(
                DataManager& dataManager,
                MeshInfoManager& meshInfoManager) : 
                                dataPorts_(dataManager),
                                setsMakerU_(meshInfoManager),
                                setsMakerV_(meshInfoManager) {

}

RhsVelocitySets::shPtrMapAbstRhsVelocity RhsVelocitySets::createSetForU() {
    return setsMakerU_.createSetForU(dataPorts_);
}

RhsVelocitySets::shPtrMapAbstRhsVelocity RhsVelocitySets::createSetForV() {
    return setsMakerV_.createSetForV(dataPorts_);
}

}