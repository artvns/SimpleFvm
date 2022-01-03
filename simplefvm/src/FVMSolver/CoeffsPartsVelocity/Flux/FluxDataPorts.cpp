#include "FluxDataPorts.h"


namespace fvmsolver {

FluxDataPorts::FluxDataPorts(
                        DataManager& dataManager) :
                                    dataManager_(dataManager) {

}


std::unique_ptr<UFluxPort> FluxDataPorts::createPortU(std::string name) {
    return std::move(
        std::unique_ptr<UFluxPort>(
            new UFluxPort(
                dataManager_.getFluidProperties(), 
                dataManager_.getFields(),
                dataManager_.getMeshParametersU(),
                dataManager_.getCellNumsGlobalU(name),
                dataManager_.getAdjCellGlobalNumsU(name))));
}


std::unique_ptr<VFluxPort> FluxDataPorts::createPortV(std::string name) {
    return std::move(
        std::unique_ptr<VFluxPort>(
            new VFluxPort(
                dataManager_.getFluidProperties(), 
                dataManager_.getFields(),
                dataManager_.getMeshParametersV(),
                dataManager_.getCellNumsGlobalV(name),
                dataManager_.getAdjCellGlobalNumsV(name))));
}

}