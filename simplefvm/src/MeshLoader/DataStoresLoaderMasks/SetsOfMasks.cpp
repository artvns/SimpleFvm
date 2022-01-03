#include "SetsOfMasks.h"

namespace meshloader {


SetsOfMasks::SetsOfMasks() {

}

void SetsOfMasks::clearSets(datastores::GlobalDataStores& dataStores) {
    dataStores.clearSets();
}

void SetsOfMasks::createMaskSetsU(datastores::GlobalDataStores& dataStores, 
                                        const MeshInformation& meshInfoU) {

    for (size_t i = 0; i < meshInfoU.getNumberOfParts(); i++) {

        dataStores.createCellNumsGlobalU(meshInfoU.getFaceName(i));
        dataStores.createCellNumsInteriorU(meshInfoU.getFaceName(i));
        dataStores.createAdjCellGlobalNumsU(meshInfoU.getFaceName(i));
        dataStores.createAdjCellInterNumsU(meshInfoU.getFaceName(i));

        mapCellNumsGlobalU_.insert(
            std::make_pair(
                meshInfoU.getFaceName(i),
                std::unique_ptr<CellNumsGlobalMask>(
                    new CellNumsGlobalMask(
                        dataStores.getCellNumsGlobalSetsU(
                                            meshInfoU.getFaceName(i))
                    )
                )
            )
        );

        mapCellNumsInteriorU_.insert(
            std::make_pair(
                meshInfoU.getFaceName(i),
                std::unique_ptr<CellNumsInteriorMask>(
                    new CellNumsInteriorMask(
                        dataStores.getCellNumsInteriorSetsU(
                                            meshInfoU.getFaceName(i))
                    )
                )
            )
        );

        mapAdjCellGlobalNumsU_.insert(
            std::make_pair(
                meshInfoU.getFaceName(i),
                std::unique_ptr<AdjCellGlobalNumsUMask>(
                    new AdjCellGlobalNumsUMask(
                        dataStores.getAdjCellGlobalNumsSetsU(
                                            meshInfoU.getFaceName(i))
                    )
                )
            )
        );

        mapAdjCellInteriorNumsU_.insert(
            std::make_pair(
                meshInfoU.getFaceName(i),
                std::unique_ptr<AdjCellInteriorNumsUMask>(
                    new AdjCellInteriorNumsUMask(
                        dataStores.getAdjCellInterNumsSetsU(
                                            meshInfoU.getFaceName(i))
                    )
                )
            )
        );
    }
}

void SetsOfMasks::createMaskSetsV(datastores::GlobalDataStores& dataStores, 
                                        const MeshInformation& meshInfoV) {

    for (size_t i = 0; i < meshInfoV.getNumberOfParts(); i++) {

        dataStores.createCellNumsGlobalV(meshInfoV.getFaceName(i));
        dataStores.createCellNumsInteriorV(meshInfoV.getFaceName(i));
        dataStores.createAdjCellGlobalNumsV(meshInfoV.getFaceName(i));
        dataStores.createAdjCellInterNumsV(meshInfoV.getFaceName(i));


        mapCellNumsGlobalV_.insert(
            std::make_pair(
                meshInfoV.getFaceName(i),
                std::unique_ptr<CellNumsGlobalMask>(
                    new CellNumsGlobalMask(
                        dataStores.getCellNumsGlobalSetsV(
                                            meshInfoV.getFaceName(i))
                    )
                )
            )
        );

        mapCellNumsInteriorV_.insert(
            std::make_pair(
                meshInfoV.getFaceName(i),
                std::unique_ptr<CellNumsInteriorMask>(
                    new CellNumsInteriorMask(
                        dataStores.getCellNumsInteriorSetsV(
                                            meshInfoV.getFaceName(i))
                    )
                )
            )
        );

        mapAdjCellGlobalNumsV_.insert(
            std::make_pair(
                meshInfoV.getFaceName(i),
                std::unique_ptr<AdjCellGlobalNumsVMask>(
                    new AdjCellGlobalNumsVMask(
                        dataStores.getAdjCellGlobalNumsSetsV(
                                            meshInfoV.getFaceName(i))
                    )
                )
            )
        );

        mapAdjCellInteriorNumsV_.insert(
            std::make_pair(
                meshInfoV.getFaceName(i),
                std::unique_ptr<AdjCellInteriorNumsVMask>(
                    new AdjCellInteriorNumsVMask(
                        dataStores.getAdjCellInterNumsSetsV(
                                            meshInfoV.getFaceName(i))
                    )
                )
            )
        );
    }
}

void SetsOfMasks::createMaskSetsP(datastores::GlobalDataStores& dataStores, 
                                        const MeshInformation& meshInfoP) {

    for (size_t i = 0; i < meshInfoP.getNumberOfParts(); i++) {

        dataStores.createCellNumsGlobalP(meshInfoP.getFaceName(i));
        dataStores.createCellNumsInteriorP(meshInfoP.getFaceName(i));
        dataStores.createAdjCellGlobalNumsP(meshInfoP.getFaceName(i));
        dataStores.createAdjCellInterNumsP(meshInfoP.getFaceName(i));

        mapCellNumsGlobalP_.insert(
            std::make_pair(
                meshInfoP.getFaceName(i),
                std::unique_ptr<CellNumsGlobalMask>(
                    new CellNumsGlobalMask(
                        dataStores.getCellNumsGlobalSetsP(
                                            meshInfoP.getFaceName(i))
                    )
                )
            )
        );

        mapCellNumsInteriorP_.insert(
            std::make_pair(
                meshInfoP.getFaceName(i),
                std::unique_ptr<CellNumsInteriorMask>(
                    new CellNumsInteriorMask(
                        dataStores.getCellNumsInteriorSetsP(
                                            meshInfoP.getFaceName(i))
                    )
                )
            )
        );

        mapAdjCellGlobalNumsP_.insert(
            std::make_pair(
                meshInfoP.getFaceName(i),
                std::unique_ptr<AdjCellGlobalNumsPMask>(
                    new AdjCellGlobalNumsPMask(
                        dataStores.getAdjCellGlobalNumsSetsP(
                                            meshInfoP.getFaceName(i))
                    )
                )
            )
        );

        mapAdjCellInteriorNumsP_.insert(
            std::make_pair(
                meshInfoP.getFaceName(i),
                std::unique_ptr<AdjCellInteriorNumsPMask>(
                    new AdjCellInteriorNumsPMask(
                        dataStores.getAdjCellInterNumsSetsP(
                                            meshInfoP.getFaceName(i))
                    )
                )
            )
        );
    }
}


CellNumsGlobalMask& SetsOfMasks::getCellNumsGlobalUMask(std::string partName) {
    return *mapCellNumsGlobalU_[partName];
}

CellNumsGlobalMask& SetsOfMasks::getCellNumsGlobalVMask(std::string partName) {
    return *mapCellNumsGlobalV_[partName];
}

CellNumsGlobalMask& SetsOfMasks::getCellNumsGlobalPMask(std::string partName) {
    return *mapCellNumsGlobalP_[partName];
}

AdjCellGlobalNumsUMask& SetsOfMasks::getAdjCellGlobalNumsUMask(std::string partName) {
    return *mapAdjCellGlobalNumsU_[partName];
}

AdjCellGlobalNumsVMask& SetsOfMasks::getAdjCellGlobalNumsVMask(std::string partName) {
    return *mapAdjCellGlobalNumsV_[partName];
}

AdjCellGlobalNumsPMask& SetsOfMasks::getAdjCellGlobalNumsPMask(std::string partName) {
    return *mapAdjCellGlobalNumsP_[partName];
}


CellNumsInteriorMask& SetsOfMasks::getCellInterNumsUMask(std::string partName) {
    return *mapCellNumsInteriorU_[partName];
}

CellNumsInteriorMask& SetsOfMasks::getCellInterNumsVMask(std::string partName) {
    return *mapCellNumsInteriorV_[partName];
}

CellNumsInteriorMask& SetsOfMasks::getCellInterNumsPMask(std::string partName) {
    return *mapCellNumsInteriorP_[partName];
}

AdjCellInteriorNumsUMask& SetsOfMasks::getAdjCellInterNumsUMask(std::string partName) {
    return *mapAdjCellInteriorNumsU_[partName];
}

AdjCellInteriorNumsVMask& SetsOfMasks::getAdjCellInterNumsVMask(std::string partName) {
    return *mapAdjCellInteriorNumsV_[partName];
}

AdjCellInteriorNumsPMask& SetsOfMasks::getAdjCellInterNumsPMask(std::string partName) {
    return *mapAdjCellInteriorNumsP_[partName];
}

}