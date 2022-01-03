#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_DATAMANAGER_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_DATAMANAGER_H

#include <vector>
#include <string>
#include <map>

#include "DataStores/GlobalDataStores.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsPMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsUMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsVMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsPMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsUMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsVMask.h"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/MeshInformation/SolverMeshInfoMask.h"
#include "FVMSolver/DataReciever/AdjacentCellsType/SolverAdjCellsTypeMask.h"

#include "SolverSingleMasks.h"
#include "SolverSetsOfMasks.h"
#include "DataValidation/FluidPropsValidatior.h"


namespace fvmsolver {

class DataManager {
public:
    DataManager(datastores::GlobalDataStores& dataStores);

    void createDataSetsMasks();
    void validateRecievedData();

    SolverFieldsMask&             getFields();
    SolverFluidPropsMask&         getFluidProperties();
    SolverMeshParamsMask&         getMeshParametersP();
    SolverMeshParamsMask&         getMeshParametersU();
    SolverMeshParamsMask&         getMeshParametersV();
    SolverMeshInfoMask&           getMeshInfoP();
    SolverMeshInfoMask&           getMeshInfoU();
    SolverMeshInfoMask&           getMeshInfoV();
    SolverAdjCellsTypeMask&       getAdjCellTypesU();
    SolverAdjCellsTypeMask&       getAdjCellTypesV();
    SolverAdjCellsTypeMask&       getAdjCellTypesP();

    SolverCellNumsGlobalMask&         getCellNumsGlobalU(std::string partName);
    SolverCellNumsGlobalMask&         getCellNumsGlobalV(std::string partName);
    SolverCellNumsGlobalMask&         getCellNumsGlobalP(std::string partName);
    SolverAdjCellGlobalNumsUMask&     getAdjCellGlobalNumsU(std::string partName);
    SolverAdjCellGlobalNumsVMask&     getAdjCellGlobalNumsV(std::string partName);
    SolverAdjCellGlobalNumsPMask&     getAdjCellGlobalNumsP(std::string partName);
    SolverCellNumsInteriorMask&       getCellInterNumsU(std::string partName);
    SolverCellNumsInteriorMask&       getCellInterNumsV(std::string partName);
    SolverCellNumsInteriorMask&       getCellInterNumsP(std::string partName);
    SolverAdjCellInteriorNumsUMask&   getAdjCellInterNumsU(std::string partName);
    SolverAdjCellInteriorNumsVMask&   getAdjCellInterNumsV(std::string partName);
    SolverAdjCellInteriorNumsPMask&   getAdjCellInterNumsP(std::string partName);

private:
    SolverSingleMasks singleMasks_;
    SolverSetsOfMasks setsOfMasks_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_DATAMANAGER_H