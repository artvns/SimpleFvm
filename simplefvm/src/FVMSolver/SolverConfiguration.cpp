#include "SolverConfiguration.h"

namespace fvmsolver {

SolverConfiguration::SolverConfiguration(
    Config& config,
    MathToolsManager& mathToolsManager,
    DataManager& dataManager,
    BcManager& bcManager,
    SolverDataStoresCreator& solverDataStores,
    MeshInfoManager& meshInfoManager) : 
            coeffsPartsCommon_          (dataManager, 
                                         meshInfoManager, 
                                         solverDataStores),
            coeffsPartsVelocity_        (dataManager, 
                                         meshInfoManager,
                                         bcManager,
                                         config),
            coeffsPartsPressure_        (dataManager, 
                                         meshInfoManager, 
                                         mathToolsManager, 
                                         solverDataStores),
            sleMatrixBuilderCreator_    (meshInfoManager,
                                         solverDataStores, 
                                         coeffsPartsCommon_,
                                         coeffsPartsVelocity_,
                                         coeffsPartsPressure_),
            residsCalculatorsCreator_   (dataManager, 
                                         meshInfoManager,
                                         mathToolsManager,
                                         solverDataStores),
            scalarCalculatorCreator_    (mathToolsManager, 
                                         sleMatrixBuilderCreator_),
            fieldsCorrectorsCreator_    (dataManager, 
                                         meshInfoManager, 
                                         mathToolsManager,
                                         solverDataStores),
            simpleBuilder_              (config,
                                         scalarCalculatorCreator_,
                                         fieldsCorrectorsCreator_,
                                         residsCalculatorsCreator_,
                                         residsOutputerCreator_),
            fieldsInterpolatorsCreator_ (dataManager, meshInfoManager),
            residsOutputerCreator_      (config) {

}

void SolverConfiguration::configureAlgorithmComponents() {
    residsOutputerCreator_.configureResidsOutputer();
}

void SolverConfiguration::configureAlgorithm() {
    pAlgorithm_ = algorithmCreator_.createSimple2D(simpleBuilder_);
}

void SolverConfiguration::calculate() {
    pAlgorithm_->calculate();
    fieldsInterpolatorsCreator_.createInterpolatorU()->interpolateField();
    fieldsInterpolatorsCreator_.createInterpolatorV()->interpolateField();
}

}