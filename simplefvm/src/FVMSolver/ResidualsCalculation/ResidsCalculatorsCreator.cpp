#include "ResidsCalculatorsCreator.h"

namespace fvmsolver {

ResidsCalculatorsCreator::ResidsCalculatorsCreator(
    DataManager& dataManager, 
    MeshInfoManager& meshInfoManager,
    MathToolsManager& mathToolsManager,
    SolverDataStoresCreator& solverDataManager) :
                residCalculatorSets_( dataManager, 
                                        meshInfoManager,
                                        mathToolsManager,
                                        solverDataManager),
                meshInfoManager_(meshInfoManager) {

}

std::shared_ptr<ResidualsCalculator> ResidsCalculatorsCreator::createResidsCalculatorU() {
    spResidsCalculatorU_ = std::shared_ptr<ResidualsCalculator>(
        new ResidualsCalculator(
            *meshInfoManager_.getMeshInfoU(),
            residCalculatorSets_.createSetU())
    );

    return spResidsCalculatorU_;
}

std::shared_ptr<ResidualsCalculator> ResidsCalculatorsCreator::createResidsCalculatorV() {
    spResidsCalculatorV_ = std::shared_ptr<ResidualsCalculator>(
        new ResidualsCalculator(
            *meshInfoManager_.getMeshInfoV(),
            residCalculatorSets_.createSetV())
    );

    return spResidsCalculatorV_;
}

std::shared_ptr<ResidualsCalculator> ResidsCalculatorsCreator::createResidsCalculatorP() {
    spResidsCalculatorP_ = std::shared_ptr<ResidualsCalculator>(
        new ResidualsCalculator(
            *meshInfoManager_.getMeshInfoP(),
            residCalculatorSets_.createSetP())
    );

    return spResidsCalculatorP_;
}

}