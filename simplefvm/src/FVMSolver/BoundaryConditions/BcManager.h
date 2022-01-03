#ifndef SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCMANAGER_H
#define SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCMANAGER_H

#include <memory>
#include <string>
#include <map>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/DataReciever/MeshInformation/SolverMeshInfoMask.h"
#include "FVMSolver/BoundaryConditions/PartsTypeInfo.h"

#include "BcParametersStores/MovingWallBcParamsStore.h"
#include "BcChecking/BcNamesValidation.h"
#include "BcChecking/BcDefinitionStatusCheck.h"


namespace fvmsolver {

class BcManager {
private:
    using uPtrMovingWallBcParamsStore = std::unique_ptr<MovingWallBcParamsStore>;

public:
    BcManager(DataManager& dataManager);

    void checkBoundaryConditions();

    void defineInteriorPart      (const std::string name);
    void defineVelocityInletPart (const std::string name);
    void definePressureInletPart (const std::string name);
    void definePressureOutletPart(const std::string name);
    void defineMovingWallPart    (const std::string name, 
                                    const double wallVelocity);
    void defineStaticWallPart    (const std::string name);

    PartsTypeInfo& getPartsTypeInfo();
    MovingWallBcParamsStore& getMovingWallBcParamsStore(std::string bcName); 

private:
    PartsTypeInfo pPartsTypeInfo_;
    BcNamesValidation bcNamesValidation_;
    BcDefinitionStatusCheck bcDefinitionStatusCheck_;
    
    std::map<std::string, uPtrMovingWallBcParamsStore> mapMovingWallBcParamsSet_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCMANAGER_H