#include "SolverSetsOfMasks.h"

namespace fvmsolver {

SolverSetsOfMasks::SolverSetsOfMasks(
        datastores::GlobalDataStores& dataStores) : 
                                dataStores_(dataStores) {

}


void SolverSetsOfMasks::createMaskSetsU() {
    for (size_t i = 0; i < dataStores_.getMeshInfoStoreU().getDomainPartsAmount(); i++) {

        std::string partName = dataStores_.getMeshInfoStoreU().getPartName().getValue(i);

        mapCellNumsGlobalU_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverCellNumsGlobalMask>(
                    new SolverCellNumsGlobalMask(
                        dataStores_.getCellNumsGlobalSetsU(partName))
                )
            )
        );

        mapCellNumsInteriorU_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverCellNumsInteriorMask>(
                    new SolverCellNumsInteriorMask(
                        dataStores_.getCellNumsInteriorSetsU(partName))
                )
            )
        );

        mapAdjCellGlobalNumsU_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverAdjCellGlobalNumsUMask>(
                    new SolverAdjCellGlobalNumsUMask(
                        dataStores_.getAdjCellGlobalNumsSetsU(partName))
                )
            )
        );

        mapAdjCellInteriorNumsU_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverAdjCellInteriorNumsUMask>(
                    new SolverAdjCellInteriorNumsUMask(
                        dataStores_.getAdjCellInterNumsSetsU(partName))
                )
            )
        );
    }
}

void SolverSetsOfMasks::createMaskSetsV() {
    for (size_t i = 0; i < dataStores_.getMeshInfoStoreV().getDomainPartsAmount(); i++) {

        std::string partName = dataStores_.getMeshInfoStoreV().getPartName().getValue(i);

        mapCellNumsGlobalV_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverCellNumsGlobalMask>(
                    new SolverCellNumsGlobalMask(
                        dataStores_.getCellNumsGlobalSetsV(partName))
                )
            )
        );

        mapCellNumsInteriorV_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverCellNumsInteriorMask>(
                    new SolverCellNumsInteriorMask(
                        dataStores_.getCellNumsInteriorSetsV(partName))
                )
            )
        );

        mapAdjCellGlobalNumsV_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverAdjCellGlobalNumsVMask>(
                    new SolverAdjCellGlobalNumsVMask(
                        dataStores_.getAdjCellGlobalNumsSetsV(partName))
                )
            )
        );

        mapAdjCellInteriorNumsV_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverAdjCellInteriorNumsVMask>(
                    new SolverAdjCellInteriorNumsVMask(
                        dataStores_.getAdjCellInterNumsSetsV(partName))
                )
            )
        );
    }
}

void SolverSetsOfMasks::createMaskSetsP() {
    for (size_t i = 0; i < dataStores_.getMeshInfoStoreP().getDomainPartsAmount(); i++) {

        std::string partName = dataStores_.getMeshInfoStoreP().getPartName().getValue(i);

        mapCellNumsGlobalP_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverCellNumsGlobalMask>(
                    new SolverCellNumsGlobalMask(
                        dataStores_.getCellNumsGlobalSetsP(partName))
                )
            )
        );

        mapCellNumsInteriorP_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverCellNumsInteriorMask>(
                    new SolverCellNumsInteriorMask(
                        dataStores_.getCellNumsInteriorSetsP(partName))
                )
            )
        );

        mapAdjCellGlobalNumsP_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverAdjCellGlobalNumsPMask>(
                    new SolverAdjCellGlobalNumsPMask(
                        dataStores_.getAdjCellGlobalNumsSetsP(partName))
                )
            )
        );

        mapAdjCellInteriorNumsP_.insert(
            std::make_pair(
                partName,
                std::unique_ptr<SolverAdjCellInteriorNumsPMask>(
                    new SolverAdjCellInteriorNumsPMask(
                        dataStores_.getAdjCellInterNumsSetsP(partName))
                )
            )
        );
    }
}













SolverCellNumsGlobalMask& SolverSetsOfMasks::getCellNumsGlobalUMask(
                                                std::string partName) {
    return *mapCellNumsGlobalU_[partName];
}

SolverCellNumsGlobalMask& SolverSetsOfMasks::getCellNumsGlobalVMask(
                                                std::string partName) {
    return *mapCellNumsGlobalV_[partName];
}

SolverCellNumsGlobalMask& SolverSetsOfMasks::getCellNumsGlobalPMask(
                                                std::string partName) {
    return *mapCellNumsGlobalP_[partName];
}


SolverAdjCellGlobalNumsUMask& SolverSetsOfMasks::getAdjCellGlobalNumsUMask(
                                                    std::string partName) {
    return *mapAdjCellGlobalNumsU_[partName];
}

SolverAdjCellGlobalNumsVMask& SolverSetsOfMasks::getAdjCellGlobalNumsVMask(
                                                    std::string partName) {
    return *mapAdjCellGlobalNumsV_[partName];
}

SolverAdjCellGlobalNumsPMask& SolverSetsOfMasks::getAdjCellGlobalNumsPMask(
                                                    std::string partName) {
    return *mapAdjCellGlobalNumsP_[partName];
}


SolverCellNumsInteriorMask& SolverSetsOfMasks::getCellInterNumsUMask(
                                                    std::string partName) {
    return *mapCellNumsInteriorU_[partName];
}

SolverCellNumsInteriorMask& SolverSetsOfMasks::getCellInterNumsVMask(
                                                    std::string partName) {
    return *mapCellNumsInteriorV_[partName];
}

SolverCellNumsInteriorMask& SolverSetsOfMasks::getCellInterNumsPMask(
                                                    std::string partName) {
    return *mapCellNumsInteriorP_[partName];
}


SolverAdjCellInteriorNumsUMask& SolverSetsOfMasks::getAdjCellInterNumsUMask(
                                                    std::string partName) {
    return *mapAdjCellInteriorNumsU_[partName];
}

SolverAdjCellInteriorNumsVMask& SolverSetsOfMasks::getAdjCellInterNumsVMask(
                                                    std::string partName) {
    return *mapAdjCellInteriorNumsV_[partName];
}

SolverAdjCellInteriorNumsPMask& SolverSetsOfMasks::getAdjCellInterNumsPMask(
                                                    std::string partName) {
    return *mapAdjCellInteriorNumsP_[partName];
}

}