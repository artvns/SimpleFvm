#include "CellNumsDataPorts.h"


namespace fvmsolver {

CellNumsDataPorts::CellNumsDataPorts(
                        DataManager& dataManager) :
                                    dataManager_(dataManager) {

}

std::unique_ptr<CellNumbersPort> CellNumsDataPorts::createPortU(std::string name) {
    return std::move(
        std::unique_ptr<CellNumbersPort>(
            new CellNumbersPort(dataManager_.getCellInterNumsU(name))));
}

std::unique_ptr<CellNumbersPort> CellNumsDataPorts::createPortV(std::string name) {
    return std::move(
        std::unique_ptr<CellNumbersPort>(
            new CellNumbersPort(dataManager_.getCellInterNumsV(name))));
}

std::unique_ptr<CellNumbersPort> CellNumsDataPorts::createPortP(std::string name) {
    return std::move(
        std::unique_ptr<CellNumbersPort>(
            new CellNumbersPort(dataManager_.getCellInterNumsP(name))));
}

}