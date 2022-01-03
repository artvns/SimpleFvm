#include "MeshInfoManager.h"

namespace fvmsolver {

MeshInfoManager::MeshInfoManager(  
                        DataManager& dataManager, 
                        PartsTypeInfo& partsTypeInfo) :
                                        dataManager_(dataManager),
                                        partsTypeInfo_(partsTypeInfo) {
    
}

void MeshInfoManager::createMeshInfo() {
    createMeshInfoP();
    createMeshInfoU();
    createMeshInfoV();
}

std::unique_ptr<MeshInfo>& MeshInfoManager::getMeshInfoP() {
    return spMeshInfoP_;
}

std::unique_ptr<MeshInfo>& MeshInfoManager::getMeshInfoU() {
    return spMeshInfoU_;
}

std::unique_ptr<MeshInfo>& MeshInfoManager::getMeshInfoV() {
    return spMeshInfoV_;
}

void MeshInfoManager::createMeshInfoP() {
    spMeshInfoP_ = std::unique_ptr<MeshInfo>(
            new MeshInfo(partsTypeInfo_, dataManager_.getMeshInfoP()));
}

void MeshInfoManager::createMeshInfoU() {
    spMeshInfoU_ = std::unique_ptr<MeshInfo>(
            new MeshInfo(partsTypeInfo_, dataManager_.getMeshInfoU()));
}

void MeshInfoManager::createMeshInfoV() {
    spMeshInfoV_ = std::unique_ptr<MeshInfo>(
            new MeshInfo(partsTypeInfo_, dataManager_.getMeshInfoV()));
}

}