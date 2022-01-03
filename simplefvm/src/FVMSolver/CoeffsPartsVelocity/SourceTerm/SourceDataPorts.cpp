#include "SourceDataPorts.h"

namespace fvmsolver {

SourceDataPorts::SourceDataPorts(
                        DataManager& dataManager,
                        BcManager& bcManager) :
                                dataManager_(dataManager),
                                bcManager_(bcManager) {

}

std::unique_ptr<AbstractSourcePort> SourceDataPorts::createPortU(
                                                    std::string name) {
    if (bcManager_.getPartsTypeInfo().isStaticWall(name)) {
        return std::move(
            std::unique_ptr<StaticWallSourcePort>(
                new StaticWallSourcePort(
                    dataManager_.getFluidProperties(), 
                    dataManager_.getMeshParametersU(),
                    dataManager_.getAdjCellTypesU(),
                    dataManager_.getCellNumsGlobalU(name))));
    }
    else {
        return std::move(
            std::unique_ptr<MovingWallSourcePort>(
                new MovingWallSourcePort(
                    dataManager_.getFluidProperties(), 
                    dataManager_.getMeshParametersU(),
                    dataManager_.getAdjCellTypesU(),
                    dataManager_.getCellNumsGlobalU(name),
                    bcManager_.getMovingWallBcParamsStore(name))));
    }
}

std::unique_ptr<AbstractSourcePort> SourceDataPorts::createPortV(
                                                    std::string name) {
    if (bcManager_.getPartsTypeInfo().isStaticWall(name)) {
        return std::move(
            std::unique_ptr<StaticWallSourcePort>(
                new StaticWallSourcePort(
                    dataManager_.getFluidProperties(), 
                    dataManager_.getMeshParametersV(),
                    dataManager_.getAdjCellTypesV(),
                    dataManager_.getCellNumsGlobalV(name))));
    }
    else {
        return std::move(
            std::unique_ptr<MovingWallSourcePort>(
                new MovingWallSourcePort(
                    dataManager_.getFluidProperties(), 
                    dataManager_.getMeshParametersV(),
                    dataManager_.getAdjCellTypesV(),
                    dataManager_.getCellNumsGlobalV(name),
                    bcManager_.getMovingWallBcParamsStore(name))));
    }
}

}