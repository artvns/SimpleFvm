#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_SOLVERSINGLEMASKS_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_SOLVERSINGLEMASKS_H

#include <string>

#include "DataStores/GlobalDataStores.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/MeshInformation/SolverMeshInfoMask.h"
#include "FVMSolver/DataReciever/AdjacentCellsType/SolverAdjCellsTypeMask.h"


namespace fvmsolver {

class SolverSingleMasks {
public:
    SolverSingleMasks(datastores::GlobalDataStores& dataStores);

    SolverFieldsMask&           getFieldsMask();
    SolverFluidPropsMask&       getFluidPropertiesMask();
    SolverMeshParamsMask&       getMeshParametersMaskP();
    SolverMeshParamsMask&       getMeshParametersMaskU();
    SolverMeshParamsMask&       getMeshParametersMaskV();
    SolverMeshInfoMask&         getMeshInfoMaskP();
    SolverMeshInfoMask&         getMeshInfoMaskU();
    SolverMeshInfoMask&         getMeshInfoMaskV();
    SolverAdjCellsTypeMask&     getAdjCellTypesMaskU();
    SolverAdjCellsTypeMask&     getAdjCellTypesMaskV();
    SolverAdjCellsTypeMask&     getAdjCellTypesMaskP();

private:
    SolverFieldsMask            fieldsMask_;
    SolverFluidPropsMask        fluidPropertiesMask_;
    SolverMeshParamsMask        meshParamsMaskP_;
    SolverMeshParamsMask        meshParamsMaskU_;
    SolverMeshParamsMask        meshParamsMaskV_;
    SolverMeshInfoMask          meshInformationMaskP_;
    SolverMeshInfoMask          meshInformationMaskU_;
    SolverMeshInfoMask          meshInformationMaskV_;
    SolverAdjCellsTypeMask      adjCellsTypeMaskP_;
    SolverAdjCellsTypeMask      adjCellsTypeMaskU_;
    SolverAdjCellsTypeMask      adjCellsTypeMaskV_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_SOLVERSINGLEMASKS_H