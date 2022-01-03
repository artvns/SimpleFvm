#include "FieldCorrectorPorts.h"


namespace fvmsolver {

FieldCorrectorPorts::FieldCorrectorPorts(
                    DataManager& dataManager, 
                    MathToolsManager& mathToolsManager,
                    MeshInfoManager& meshInfoManager,
                    SolverDataStoresCreator& solverDataManager) :
                            dataManager_(dataManager),
                            mathToolsManager_(mathToolsManager),
                            meshInfoManager_(meshInfoManager),
                            solverDataManager_(solverDataManager) {

}

std::unique_ptr<FieldCorrectorUPort> FieldCorrectorPorts::createPortU(
                                                    std::string name) {
    return std::move(
        std::unique_ptr<FieldCorrectorUPort>(
            new FieldCorrectorUPort(
                *meshInfoManager_.getMeshInfoU(), 
                dataManager_.getFields(),
                dataManager_.getCellInterNumsU(name),
                dataManager_.getCellNumsGlobalU(name),
                dataManager_.getAdjCellInterNumsU(name),
                *mathToolsManager_.getScalarsStore(),
                solverDataManager_.getCoeffsCalculatorsStore())));
}


std::unique_ptr<FieldCorrectorVPort> FieldCorrectorPorts::createPortV(
                                                    std::string name) {
    return std::move(
        std::unique_ptr<FieldCorrectorVPort>(
            new FieldCorrectorVPort(
                *meshInfoManager_.getMeshInfoV(), 
                dataManager_.getFields(),
                dataManager_.getCellInterNumsV(name),
                dataManager_.getCellNumsGlobalV(name),
                dataManager_.getAdjCellInterNumsV(name),
                *mathToolsManager_.getScalarsStore(),
                solverDataManager_.getCoeffsCalculatorsStore())));
}


std::unique_ptr<FieldCorrectorPPort> FieldCorrectorPorts::createPortP(
                                                    std::string name) {
    return std::move(
        std::unique_ptr<FieldCorrectorPPort>(
            new FieldCorrectorPPort(
                *meshInfoManager_.getMeshInfoP(), 
                dataManager_.getFields(),
                dataManager_.getCellInterNumsP(name),
                dataManager_.getCellNumsGlobalP(name),
                *mathToolsManager_.getScalarsStore())));
}

}