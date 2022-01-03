#include "DataManager.h"

namespace fvmsolver {

DataManager::DataManager(
        datastores::GlobalDataStores& dataStores) : 
                                    singleMasks_(dataStores),
                                    setsOfMasks_(dataStores) {

}

void DataManager::createDataSetsMasks() {
    setsOfMasks_.createMaskSetsU();
    setsOfMasks_.createMaskSetsV();
    setsOfMasks_.createMaskSetsP();
}

void DataManager::validateRecievedData() {
    FluidPropsValidatior fluidPropsValidatior_(singleMasks_);
    
    fluidPropsValidatior_.validateData();
}


SolverFieldsMask& DataManager::getFields() {
    return singleMasks_.getFieldsMask();
}

SolverFluidPropsMask& DataManager::getFluidProperties() {
    return singleMasks_.getFluidPropertiesMask();
}


SolverMeshParamsMask& DataManager::getMeshParametersP() {
    return singleMasks_.getMeshParametersMaskP();
}
SolverMeshParamsMask& DataManager::getMeshParametersU() {
    return singleMasks_.getMeshParametersMaskU();
}
SolverMeshParamsMask& DataManager::getMeshParametersV() {
    return singleMasks_.getMeshParametersMaskV();
}


SolverMeshInfoMask& DataManager::getMeshInfoP() {
    return singleMasks_.getMeshInfoMaskP();
}
SolverMeshInfoMask& DataManager::getMeshInfoU() {
    return singleMasks_.getMeshInfoMaskU();
}
SolverMeshInfoMask& DataManager::getMeshInfoV() {
    return singleMasks_.getMeshInfoMaskV();
}


SolverAdjCellsTypeMask& DataManager::getAdjCellTypesU() {
    return singleMasks_.getAdjCellTypesMaskU();
}
SolverAdjCellsTypeMask& DataManager::getAdjCellTypesV() {
    return singleMasks_.getAdjCellTypesMaskV();
}
SolverAdjCellsTypeMask& DataManager::getAdjCellTypesP() {
    return singleMasks_.getAdjCellTypesMaskP();
}


SolverCellNumsGlobalMask& DataManager::getCellNumsGlobalU(std::string partName) {
    return setsOfMasks_.getCellNumsGlobalUMask(partName);
}

SolverCellNumsGlobalMask& DataManager::getCellNumsGlobalV(std::string partName) {
    return setsOfMasks_.getCellNumsGlobalVMask(partName);
}

SolverCellNumsGlobalMask& DataManager::getCellNumsGlobalP(std::string partName) {
    return setsOfMasks_.getCellNumsGlobalPMask(partName);
}


SolverAdjCellGlobalNumsUMask& DataManager::getAdjCellGlobalNumsU(std::string partName) {
    return setsOfMasks_.getAdjCellGlobalNumsUMask(partName);
}

SolverAdjCellGlobalNumsVMask& DataManager::getAdjCellGlobalNumsV(std::string partName) {
    return setsOfMasks_.getAdjCellGlobalNumsVMask(partName);
}

SolverAdjCellGlobalNumsPMask& DataManager::getAdjCellGlobalNumsP(std::string partName) {
    return setsOfMasks_.getAdjCellGlobalNumsPMask(partName);
}


SolverCellNumsInteriorMask& DataManager::getCellInterNumsU(std::string partName) {
    return setsOfMasks_.getCellInterNumsUMask(partName);
}

SolverCellNumsInteriorMask& DataManager::getCellInterNumsV(std::string partName) {
    return setsOfMasks_.getCellInterNumsVMask(partName);
}

SolverCellNumsInteriorMask& DataManager::getCellInterNumsP(std::string partName) {
    return setsOfMasks_.getCellInterNumsPMask(partName);
}


SolverAdjCellInteriorNumsUMask& DataManager::getAdjCellInterNumsU(std::string partName) {
    return setsOfMasks_.getAdjCellInterNumsUMask(partName);
}

SolverAdjCellInteriorNumsVMask& DataManager::getAdjCellInterNumsV(std::string partName) {
    return setsOfMasks_.getAdjCellInterNumsVMask(partName);
}

SolverAdjCellInteriorNumsPMask& DataManager::getAdjCellInterNumsP(std::string partName) {
    return setsOfMasks_.getAdjCellInterNumsPMask(partName);
}

}