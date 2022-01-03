#include "DataStoreMasks.h"

namespace meshloader {


DataStoreMasks::DataStoreMasks(
            datastores::GlobalDataStores& dataStores,
            const MeshInformation& meshInfoU, 
            const MeshInformation& meshInfoV, 
            const MeshInformation& meshInfoP) :
                                dataStores_(dataStores),
                                meshInfoU_(meshInfoU),
                                meshInfoV_(meshInfoV),
                                meshInfoP_(meshInfoP),
                                singleMasks_(dataStores) {

}

void DataStoreMasks::createDataMasks() {
    setsOfMasks_.clearSets(dataStores_);
    setsOfMasks_.createMaskSetsU(dataStores_, meshInfoU_);
    setsOfMasks_.createMaskSetsV(dataStores_, meshInfoV_);
    setsOfMasks_.createMaskSetsP(dataStores_, meshInfoP_);
}

StateFlagsMask& DataStoreMasks::getStateFlagsMask() {
    return singleMasks_.getStateFlagsMask();
}

FieldsMask& DataStoreMasks::getFieldsMask() {
    return singleMasks_.getFieldsMask();
}

MeshParamsMask& DataStoreMasks::getMeshParametersMaskP() {
    return singleMasks_.getMeshParametersMaskP();
}
MeshParamsMask& DataStoreMasks::getMeshParametersMaskU() {
    return singleMasks_.getMeshParametersMaskU();
}
MeshParamsMask& DataStoreMasks::getMeshParametersMaskV() {
    return singleMasks_.getMeshParametersMaskV();
}

MeshInformationMask& DataStoreMasks::getMeshInfoMaskP() {
    return singleMasks_.getMeshInfoMaskP();
}
MeshInformationMask& DataStoreMasks::getMeshInfoMaskU() {
    return singleMasks_.getMeshInfoMaskU();
}
MeshInformationMask& DataStoreMasks::getMeshInfoMaskV() {
    return singleMasks_.getMeshInfoMaskV();
}

AdjCellsTypeMask& DataStoreMasks::getAdjCellTypesMaskU() {
    return singleMasks_.getAdjCellTypesMaskU();
}
AdjCellsTypeMask& DataStoreMasks::getAdjCellTypesMaskV() {
    return singleMasks_.getAdjCellTypesMaskV();
}
AdjCellsTypeMask& DataStoreMasks::getAdjCellTypesMaskP() {
    return singleMasks_.getAdjCellTypesMaskP();
}

MeshBuildingMask& DataStoreMasks::getMeshBuildingMask() {
    return singleMasks_.getMeshBuildingMask();
}

CellNumsGlobalMask& DataStoreMasks::getCellNumsGlobalUMask(std::string partName) {
    return setsOfMasks_.getCellNumsGlobalUMask(partName);
}

CellNumsGlobalMask& DataStoreMasks::getCellNumsGlobalVMask(std::string partName) {
    return setsOfMasks_.getCellNumsGlobalVMask(partName);
}

CellNumsGlobalMask& DataStoreMasks::getCellNumsGlobalPMask(std::string partName) {
    return setsOfMasks_.getCellNumsGlobalPMask(partName);
}

AdjCellGlobalNumsUMask& DataStoreMasks::getAdjCellGlobalNumsUMask(std::string partName) {
    return setsOfMasks_.getAdjCellGlobalNumsUMask(partName);
}

AdjCellGlobalNumsVMask& DataStoreMasks::getAdjCellGlobalNumsVMask(std::string partName) {
    return setsOfMasks_.getAdjCellGlobalNumsVMask(partName);
}

AdjCellGlobalNumsPMask& DataStoreMasks::getAdjCellGlobalNumsPMask(std::string partName) {
    return setsOfMasks_.getAdjCellGlobalNumsPMask(partName);
}


CellNumsInteriorMask& DataStoreMasks::getCellInterNumsUMask(std::string partName) {
    return setsOfMasks_.getCellInterNumsUMask(partName);
}

CellNumsInteriorMask& DataStoreMasks::getCellInterNumsVMask(std::string partName) {
    return setsOfMasks_.getCellInterNumsVMask(partName);
}

CellNumsInteriorMask& DataStoreMasks::getCellInterNumsPMask(std::string partName) {
    return setsOfMasks_.getCellInterNumsPMask(partName);
}

AdjCellInteriorNumsUMask& DataStoreMasks::getAdjCellInterNumsUMask(std::string partName) {
    return setsOfMasks_.getAdjCellInterNumsUMask(partName);
}

AdjCellInteriorNumsVMask& DataStoreMasks::getAdjCellInterNumsVMask(std::string partName) {
    return setsOfMasks_.getAdjCellInterNumsVMask(partName);
}

AdjCellInteriorNumsPMask& DataStoreMasks::getAdjCellInterNumsPMask(std::string partName) {
    return setsOfMasks_.getAdjCellInterNumsPMask(partName);
}

}