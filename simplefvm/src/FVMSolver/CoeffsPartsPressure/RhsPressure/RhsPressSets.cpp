#include "RhsPressSets.h"

namespace fvmsolver {

RhsPressSets::RhsPressSets(
                DataManager& dataManager, 
                MathToolsManager& mathToolsManager,
                MeshInfoManager& meshInfoManager) : 
                                dataPorts_(dataManager, mathToolsManager),
                                setsMaker_(meshInfoManager) {

}

RhsPressSets::shPtrMapRhsPress RhsPressSets::createSet() {
    return setsMaker_.createSetForP(dataPorts_);
}

}