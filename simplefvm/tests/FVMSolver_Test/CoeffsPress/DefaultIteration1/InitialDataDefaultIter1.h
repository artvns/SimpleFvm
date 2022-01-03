#ifndef SIMPLEFVM_FVMSOLVERTEST_COEFFSPRESS_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_COEFFSPRESS_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H

#include <cstddef>

#include "FVMSolver_Test/CommonInitData/CommonData.h"
#include "FVMSolver_Test/CommonInitData/DataDefaultIteration1/DataDefaultIter1.h"

#include "DataStores/CellNumsGlobalStores/CellNumsGlobalStore.h"
#include "DataStores/CellNumsInteriorStores/AdjCellInteriorNumsPStore.h"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsPMask.h"
#include "FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h"


namespace coeffs_p {

using namespace fvmsolver;
using namespace datastores;
using namespace commoninitdata;


class InitialDataDefaultIter1 {
public:
    InitialDataDefaultIter1(DataDefaultIter1& dataContainer);

    void createInitData();

    SolverFluidPropsMask& getFluidPropertiesMask();
    SolverMeshParamsMask& getMeshParametersMask();
    SolverCellNumsGlobalMask& getCellNumsGlobalMask();
    SolverAdjCellInteriorNumsPMask& getAdjCellInteriorNumsPMask();
    CoeffsCalculatorsStore& getCoeffsCalculatorsStore();

private:
    DataDefaultIter1& dataContainer_;

    CellNumsGlobalStore cellNumsGlobalStore_;
    AdjCellInteriorNumsPStore adjCellInteriorNumsPStore_;

    SolverCellNumsGlobalMask cellNumsGlobalMask_;
    SolverAdjCellInteriorNumsPMask adjCellInteriorNumsPMask_;

    void createCellNumsGlob();
    void createAdjCellNumsInterior();
};

}
#endif // SIMPLEFVM_FVMSOLVERTEST_COEFFSPRESS_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H