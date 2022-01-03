#include "FieldCorrectorSets.h"

namespace fvmsolver {

FieldCorrectorSets::FieldCorrectorSets(
                DataManager& dataManager, 
                MeshInfoManager& meshInfoManager,
                MathToolsManager& mathToolsManager,
                SolverDataStoresCreator& solverDataManager) : 
                        dataPorts_(dataManager, 
                                   mathToolsManager, 
                                   meshInfoManager,
                                   solverDataManager),
                        setsMakerU_(meshInfoManager),
                        setsMakerV_(meshInfoManager),
                        setsMakerP_(meshInfoManager) {

}

FieldCorrectorSets::shPtrMapAbstFieldCorrector FieldCorrectorSets::createSetU() {
    return setsMakerU_.createSetForU(dataPorts_);
}

FieldCorrectorSets::shPtrMapAbstFieldCorrector FieldCorrectorSets::createSetV() {
    return setsMakerV_.createSetForV(dataPorts_);
}

FieldCorrectorSets::shPtrMapAbstFieldCorrector FieldCorrectorSets::createSetP() {
    return setsMakerP_.createSetForP(dataPorts_);
}

}