#include "FieldInterpolatorPorts.h"

namespace fvmsolver {

FieldInterpolatorPorts::FieldInterpolatorPorts(
                        DataManager& dataManager) :
                                dataManager_(dataManager) {

}

std::unique_ptr<FieldInterpolatorUPort> FieldInterpolatorPorts::createPortU(
                                                        std::string name) {
    return std::move(
        std::unique_ptr<FieldInterpolatorUPort>(
            new FieldInterpolatorUPort(
                dataManager_.getFields(),
                dataManager_.getMeshParametersP(),
                dataManager_.getCellNumsGlobalP(name),
                dataManager_.getAdjCellGlobalNumsP(name))));
}

std::unique_ptr<FieldInterpolatorVPort> FieldInterpolatorPorts::createPortV(
                                                        std::string name) {
    return std::move(
        std::unique_ptr<FieldInterpolatorVPort>(
            new FieldInterpolatorVPort(
                dataManager_.getFields(),
                dataManager_.getMeshParametersP(),
                dataManager_.getCellNumsGlobalP(name),
                dataManager_.getAdjCellGlobalNumsP(name))));
}

}