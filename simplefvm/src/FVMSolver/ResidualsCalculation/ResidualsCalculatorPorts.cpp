#include "ResidualsCalculatorPorts.h"

namespace fvmsolver {

ResidualsCalculatorPorts::ResidualsCalculatorPorts(
                    DataManager& dataManager, 
                    MathToolsManager& mathToolsManager,
                    MeshInfoManager& meshInfoManager,
                    SolverDataStoresCreator& solverDataManager) :
                            dataManager_(dataManager),
                            mathToolsManager_(mathToolsManager),
                            meshInfoManager_(meshInfoManager),
                            solverDataManager_(solverDataManager) {

}

std::unique_ptr<ResidualsCalculatorUPort> ResidualsCalculatorPorts::createPortU(
                                                    std::string name) {
    return std::move(
        std::unique_ptr<ResidualsCalculatorUPort>(
            new ResidualsCalculatorUPort(
                dataManager_.getCellInterNumsU(name),
                *mathToolsManager_.getScalarsStore(),
                solverDataManager_.getSavedCoeffsStoreU(),
                solverDataManager_.getSavedRhsStoreU())));
}

std::unique_ptr<ResidualsCalculatorVPort> ResidualsCalculatorPorts::createPortV(
                                                    std::string name) {
    return std::move(
        std::unique_ptr<ResidualsCalculatorVPort>(
            new ResidualsCalculatorVPort(
                dataManager_.getCellInterNumsV(name),
                *mathToolsManager_.getScalarsStore(),
                solverDataManager_.getSavedCoeffsStoreV(),
                solverDataManager_.getSavedRhsStoreV())));
}

std::unique_ptr<ResidualsCalculatorPPort> ResidualsCalculatorPorts::createPortP(
                                                    std::string name) {
    return std::move(
        std::unique_ptr<ResidualsCalculatorPPort>(
            new ResidualsCalculatorPPort(
                dataManager_.getCellInterNumsP(name),
                solverDataManager_.getSavedRhsStoreP())));
}

}