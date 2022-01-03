#include "FieldsCorrectorsCreator.h"

namespace fvmsolver {

FieldsCorrectorsCreator::FieldsCorrectorsCreator(
    DataManager& dataManager, 
    MeshInfoManager& meshInfoManager,
    MathToolsManager& mathToolsManager,
    SolverDataStoresCreator& solverDataManager) :
                fieldCorrectorSets_( dataManager, 
                                        meshInfoManager,
                                        mathToolsManager,
                                        solverDataManager),
                meshInfoManager_(meshInfoManager) {

}

std::shared_ptr<FieldCorrector> FieldsCorrectorsCreator::createFiledCorrectorU() {
    spFieldCorrectorU_ = std::shared_ptr<FieldCorrector>(
        new FieldCorrector(
            *meshInfoManager_.getMeshInfoU(),
            fieldCorrectorSets_.createSetU())
    );

    return spFieldCorrectorU_;
}

std::shared_ptr<FieldCorrector> FieldsCorrectorsCreator::createFiledCorrectorV() {
    spFieldCorrectorV_ = std::shared_ptr<FieldCorrector>(
        new FieldCorrector(
            *meshInfoManager_.getMeshInfoV(),
            fieldCorrectorSets_.createSetV())
    );

    return spFieldCorrectorV_;
}

std::shared_ptr<FieldCorrector> FieldsCorrectorsCreator::createFiledCorrectorP() {
    spFieldCorrectorP_ = std::shared_ptr<FieldCorrector>(
        new FieldCorrector(
            *meshInfoManager_.getMeshInfoP(),
            fieldCorrectorSets_.createSetP())
    );

    return spFieldCorrectorP_;
}

}