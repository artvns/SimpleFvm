#include "DataExchangerPorts.h"


namespace fvmsolver {

DataExchangerPorts::DataExchangerPorts(
            DataManager& dataManager,
            SolverDataStoresCreator& solverDataStores) :
                                dataManager_(dataManager),
                                solverDataStores_(solverDataStores) {

}

std::unique_ptr<UDataExchangerPort> DataExchangerPorts::createPortU(std::string name) {
    return std::move(
        std::unique_ptr<UDataExchangerPort>(
            new UDataExchangerPort(
                dataManager_.getMeshParametersU(),
                dataManager_.getCellNumsGlobalU(name),
                dataManager_.getCellInterNumsU(name),
                solverDataStores_.getCoeffsCalculatorsStore())));
}

std::unique_ptr<VDataExchangerPort> DataExchangerPorts::createPortV(std::string name) {
    return std::move(
        std::unique_ptr<VDataExchangerPort>(
            new VDataExchangerPort(
                dataManager_.getMeshParametersV(),
                dataManager_.getCellNumsGlobalV(name),
                dataManager_.getCellInterNumsV(name),
                solverDataStores_.getCoeffsCalculatorsStore())));
}

std::unique_ptr<PDataExchangerPort> DataExchangerPorts::createPortP(std::string name) {
    return std::move(
        std::unique_ptr<PDataExchangerPort>(
            new PDataExchangerPort(
                dataManager_.getCellInterNumsP(name),
                dataManager_.getAdjCellInterNumsP(name),
                solverDataStores_.getCoeffsCalculatorsStore())));
}

}