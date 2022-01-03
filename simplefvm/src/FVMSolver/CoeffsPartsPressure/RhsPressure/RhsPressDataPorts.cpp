#include "RhsPressDataPorts.h"

namespace fvmsolver {

RhsPressDataPorts::RhsPressDataPorts(
                DataManager& dataManager,
                MathToolsManager& mathToolsManager) :
                            dataManager_(dataManager),
                            mathToolsManager_(mathToolsManager) {

}

std::unique_ptr<RhsPressPort> RhsPressDataPorts::createPortP(std::string name) {
    return std::move(
        std::unique_ptr<RhsPressPort>(
            new RhsPressPort(
                dataManager_.getFluidProperties(), 
                dataManager_.getMeshParametersP(),
                dataManager_.getCellNumsGlobalP(name),
                dataManager_.getAdjCellInterNumsP(name),
                *mathToolsManager_.getScalarsStore())));
}

}