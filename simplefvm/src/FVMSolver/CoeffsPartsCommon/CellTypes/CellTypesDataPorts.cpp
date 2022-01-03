#include "CellTypesDataPorts.h"


namespace fvmsolver {

CellTypesDataPorts::CellTypesDataPorts(
                        DataManager& dataManager) :
                                    dataManager_(dataManager) {

}

std::unique_ptr<CellTypesPort> CellTypesDataPorts::createPortU(std::string name) {
    return std::move(
        std::unique_ptr<CellTypesPort>(
            new CellTypesPort(
                dataManager_.getAdjCellTypesU(),
                dataManager_.getCellNumsGlobalU(name))));
}

std::unique_ptr<CellTypesPort> CellTypesDataPorts::createPortV(std::string name) {
    return std::move(
        std::unique_ptr<CellTypesPort>(
            new CellTypesPort(
                dataManager_.getAdjCellTypesV(),
                dataManager_.getCellNumsGlobalV(name))));
}

std::unique_ptr<CellTypesPort> CellTypesDataPorts::createPortP(std::string name) {
    return std::move(
        std::unique_ptr<CellTypesPort>(
            new CellTypesPort(
                dataManager_.getAdjCellTypesP(),
                dataManager_.getCellNumsGlobalP(name))));
}

}