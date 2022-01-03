#ifndef SIMPLEFVM_FVMSOLVERTEST_FLUXV_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_FLUXV_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H

#include <cstddef>

#include "FVMSolver_Test/CommonInitData/CommonData.h"
#include "FVMSolver_Test/CommonInitData/DataDefaultIteration2/DataDefaultIter2.h"

#include "DataStores/CellNumsGlobalStores/CellNumsGlobalStore.h"
#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsVStore.h"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsVMask.h"


namespace flux_v {

using namespace fvmsolver;
using namespace datastores;
using namespace commoninitdata;


class InitialDataDefaultIter2 {
public:
    InitialDataDefaultIter2(DataDefaultIter2& dataContainer);

    void createInitData();

    SolverFluidPropsMask& getFluidPropertiesMask();
    SolverMeshParamsMask& getMeshParametersMask();
    SolverCellNumsGlobalMask& getCellNumsGlobalMask();
    SolverAdjCellGlobalNumsVMask& getAdjCellGlobalNumsVMask();
    SolverFieldsMask& getFieldsMask();

private:
    DataDefaultIter2& dataContainer_;

    CellNumsGlobalStore cellNumsGlobalStore_;
    AdjCellGlobalNumsVStore adjCellGlobalNumsVStore_;
    SolverCellNumsGlobalMask cellNumsGlobalMask_;
    SolverAdjCellGlobalNumsVMask adjCellGlobalNumsVMask_;

    void createCellNumsGlob();
    void createAdjCellGlobalNumsV();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_FLUXV_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H