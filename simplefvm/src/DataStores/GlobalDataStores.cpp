#include "GlobalDataStores.h"

namespace datastores {

GlobalDataStores::GlobalDataStores() {

}

void GlobalDataStores::clearSets() {
    cellNumsGlobalSetsU_.clearMap();
    cellNumsGlobalSetsV_.clearMap();
    cellNumsGlobalSetsP_.clearMap();
    cellNumsInteriorSetsU_.clearMap();
    cellNumsInteriorSetsV_.clearMap();
    cellNumsInteriorSetsP_.clearMap();
    adjCellGlobalNumsSetsU_.clearMap();
    adjCellGlobalNumsSetsV_.clearMap();
    adjCellGlobalNumsSetsP_.clearMap();
    adjCellInterNumsSetsU_.clearMap();
    adjCellInterNumsSetsV_.clearMap();
    adjCellInterNumsSetsP_.clearMap();
}

SolverStateFlagsStore& GlobalDataStores::getSolverStateFlags() {
    return solverStateFlagsStore_;
}


FieldsStore& GlobalDataStores::getFieldsStore() {
    return fieldsStore_;
}

FluidPropertiesStore& GlobalDataStores::getFluidPropertiesStore() {
    return fluidPropertiesStore_;
}

MeshParametersStore& GlobalDataStores::getMeshParametersStoreP() {
    return meshParametersStoreP_;
}

MeshParametersStore& GlobalDataStores::getMeshParametersStoreU() {
    return meshParametersStoreU_;
}

MeshParametersStore& GlobalDataStores::getMeshParametersStoreV() {
    return meshParametersStoreV_;
}

MeshInfoStore& GlobalDataStores::getMeshInfoStoreP() {
    return meshInfoStoreP_;
}

MeshInfoStore& GlobalDataStores::getMeshInfoStoreU() {
    return meshInfoStoreU_;
}

MeshInfoStore& GlobalDataStores::getMeshInfoStoreV() {
    return meshInfoStoreV_;
}


AdjCellsTypeStore& GlobalDataStores::getAdjCellsTypeStoreP() {
    return adjCellsTypeStoreP_; 
}

AdjCellsTypeStore& GlobalDataStores::getAdjCellsTypeStoreU() {
    return adjCellsTypeStoreU_; 
}

AdjCellsTypeStore& GlobalDataStores::getAdjCellsTypeStoreV() {
    return adjCellsTypeStoreV_; 
}



CellNumsGlobalStore& GlobalDataStores::getCellNumsGlobalSetsU(std::string partName) {
    return *cellNumsGlobalSetsU_.getObject(partName);
}

CellNumsGlobalStore& GlobalDataStores::getCellNumsGlobalSetsV(std::string partName) {
    return *cellNumsGlobalSetsV_.getObject(partName);
}

CellNumsGlobalStore& GlobalDataStores::getCellNumsGlobalSetsP(std::string partName) {
    return *cellNumsGlobalSetsP_.getObject(partName);
}



CellNumsInteriorStore& GlobalDataStores::getCellNumsInteriorSetsU(std::string partName) {
    return *cellNumsInteriorSetsU_.getObject(partName);
}

CellNumsInteriorStore& GlobalDataStores::getCellNumsInteriorSetsV(std::string partName) {
    return *cellNumsInteriorSetsV_.getObject(partName);
}

CellNumsInteriorStore& GlobalDataStores::getCellNumsInteriorSetsP(std::string partName) {
    return *cellNumsInteriorSetsP_.getObject(partName);
}



AdjCellGlobalNumsUStore& GlobalDataStores::getAdjCellGlobalNumsSetsU(std::string partName) {
    return *adjCellGlobalNumsSetsU_.getObject(partName);
}

AdjCellGlobalNumsVStore& GlobalDataStores::getAdjCellGlobalNumsSetsV(std::string partName) {
    return *adjCellGlobalNumsSetsV_.getObject(partName);
}

AdjCellGlobalNumsPStore& GlobalDataStores::getAdjCellGlobalNumsSetsP(std::string partName) {
    return *adjCellGlobalNumsSetsP_.getObject(partName);
}



AdjCellInteriorNumsUStore& GlobalDataStores::getAdjCellInterNumsSetsU(std::string partName) {
    return *adjCellInterNumsSetsU_.getObject(partName);
}

AdjCellInteriorNumsVStore& GlobalDataStores::getAdjCellInterNumsSetsV(std::string partName) {
    return *adjCellInterNumsSetsV_.getObject(partName);
}

AdjCellInteriorNumsPStore& GlobalDataStores::getAdjCellInterNumsSetsP(std::string partName) {
    return *adjCellInterNumsSetsP_.getObject(partName);
}



MeshBuildingStore& GlobalDataStores::getMeshBuildingStore() {
    return meshBuildingStore_;
}


void GlobalDataStores::createCellNumsGlobalU(std::string partName) {
    cellNumsGlobalSetsU_.addObjectUPtr(partName, 
        std::move(uPtrCellNumsGlobalStore(new CellNumsGlobalStore())));
}

void GlobalDataStores::createCellNumsGlobalV(std::string partName) {
    cellNumsGlobalSetsV_.addObjectUPtr(partName, 
        std::move(uPtrCellNumsGlobalStore(new CellNumsGlobalStore())));
}

void GlobalDataStores::createCellNumsGlobalP(std::string partName) {
    cellNumsGlobalSetsP_.addObjectUPtr(partName, 
        std::move(uPtrCellNumsGlobalStore(new CellNumsGlobalStore())));
}


void GlobalDataStores::createCellNumsInteriorU(std::string partName) {
    cellNumsInteriorSetsU_.addObjectUPtr(partName, 
        std::move(uPtrCellNumsInteriorStore(new CellNumsInteriorStore())));
}

void GlobalDataStores::createCellNumsInteriorV(std::string partName) {
    cellNumsInteriorSetsV_.addObjectUPtr(partName, 
        std::move(uPtrCellNumsInteriorStore(new CellNumsInteriorStore())));
}

void GlobalDataStores::createCellNumsInteriorP(std::string partName) {
    cellNumsInteriorSetsP_.addObjectUPtr(partName, 
        std::move(uPtrCellNumsInteriorStore(new CellNumsInteriorStore())));
}


void GlobalDataStores::createAdjCellGlobalNumsU(std::string partName) {
    adjCellGlobalNumsSetsU_.addObjectUPtr(partName, 
        std::move(uPtrAdjCellGlobalNumsUStore(new AdjCellGlobalNumsUStore())));
}

void GlobalDataStores::createAdjCellGlobalNumsV(std::string partName) {
    adjCellGlobalNumsSetsV_.addObjectUPtr(partName, 
        std::move(uPtrAdjCellGlobalNumsVStore(new AdjCellGlobalNumsVStore())));
}

void GlobalDataStores::createAdjCellGlobalNumsP(std::string partName) {
    adjCellGlobalNumsSetsP_.addObjectUPtr(partName, 
        std::move(uPtrAdjCellGlobalNumsPStore(new AdjCellGlobalNumsPStore())));
}


void GlobalDataStores::createAdjCellInterNumsU(std::string partName) {
    adjCellInterNumsSetsU_.addObjectUPtr(partName, 
        std::move(uPtrAdjCellInteriorNumsUStore(new AdjCellInteriorNumsUStore())));
}

void GlobalDataStores::createAdjCellInterNumsV(std::string partName) {
    adjCellInterNumsSetsV_.addObjectUPtr(partName, 
        std::move(uPtrAdjCellInteriorNumsVStore(new AdjCellInteriorNumsVStore())));
}

void GlobalDataStores::createAdjCellInterNumsP(std::string partName) {
    adjCellInterNumsSetsP_.addObjectUPtr(partName, 
        std::move(uPtrAdjCellInteriorNumsPStore(new AdjCellInteriorNumsPStore())));
}

}