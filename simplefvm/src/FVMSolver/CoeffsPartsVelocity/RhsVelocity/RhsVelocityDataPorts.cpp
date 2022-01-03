#include "RhsVelocityDataPorts.h"


namespace fvmsolver {

RhsVelocityDataPorts::RhsVelocityDataPorts(
                        DataManager& dataManager) :
                                    dataManager_(dataManager){

}

std::unique_ptr<RhsUPort> RhsVelocityDataPorts::createPortU(std::string name) {
    return std::move(
        std::unique_ptr<RhsUPort>(
            new RhsUPort(
                dataManager_.getFields(),
                dataManager_.getMeshParametersU(),
                dataManager_.getCellNumsGlobalU(name),
                dataManager_.getAdjCellGlobalNumsU(name))));
}


std::unique_ptr<RhsVPort> RhsVelocityDataPorts::createPortV(std::string name) {
    return std::move(
        std::unique_ptr<RhsVPort>(
            new RhsVPort(
                dataManager_.getFields(),
                dataManager_.getMeshParametersV(),
                dataManager_.getCellNumsGlobalV(name),
                dataManager_.getAdjCellGlobalNumsV(name))));
}

}