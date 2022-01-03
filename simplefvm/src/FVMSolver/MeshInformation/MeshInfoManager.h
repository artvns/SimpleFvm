#ifndef SIMPLEFVM_FVMSOLVER_MESHINFORMATION_MESHINFOMANAGER_H
#define SIMPLEFVM_FVMSOLVER_MESHINFORMATION_MESHINFOMANAGER_H

#include <memory>
#include <vector>
#include <string>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfo.h"
#include "FVMSolver/BoundaryConditions/PartsTypeInfo.h"


namespace fvmsolver {

class MeshInfoManager {
public:
    MeshInfoManager(DataManager& dataManager, PartsTypeInfo& partsTypeInfo);

    void createMeshInfo();

    std::unique_ptr<MeshInfo>& getMeshInfoP();
    std::unique_ptr<MeshInfo>& getMeshInfoU();
    std::unique_ptr<MeshInfo>& getMeshInfoV();

private:
    DataManager& dataManager_;
    PartsTypeInfo& partsTypeInfo_;

    std::unique_ptr<MeshInfo> spMeshInfoP_ = nullptr;
    std::unique_ptr<MeshInfo> spMeshInfoU_ = nullptr;
    std::unique_ptr<MeshInfo> spMeshInfoV_ = nullptr;

    void createMeshInfoP();
    void createMeshInfoU();
    void createMeshInfoV();
};

}
#endif // SIMPLEFVM_FVMSOLVER_MESHINFORMATION_MESHINFOMANAGER_H