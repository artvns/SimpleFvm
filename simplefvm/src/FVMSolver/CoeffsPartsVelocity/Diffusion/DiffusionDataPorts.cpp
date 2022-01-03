#include "DiffusionDataPorts.h"

namespace fvmsolver {

DiffusionDataPorts::DiffusionDataPorts(
                        DataManager& dataManager) :
                                    dataManager_(dataManager) {

}


std::unique_ptr<DiffusionPort> DiffusionDataPorts::createPortU(
                                                    std::string name) {
    return std::move(
        std::unique_ptr<DiffusionPort>(
            new DiffusionPort(
                dataManager_.getFluidProperties(), 
                dataManager_.getMeshParametersU(),
                dataManager_.getCellNumsGlobalU(name))));
}


std::unique_ptr<DiffusionPort> DiffusionDataPorts::createPortV(
                                                    std::string name) {
    return std::move(
        std::unique_ptr<DiffusionPort>(
            new DiffusionPort(
                dataManager_.getFluidProperties(), 
                dataManager_.getMeshParametersV(),
                dataManager_.getCellNumsGlobalV(name))));
}

}