#ifndef SIMPLEFVM_FVMSOLVERTEST_FLUXU_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_FLUXU_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H

#include <cstddef>

#include "FVMSolver_Test/CommonInitData/CommonData.h"
#include "FVMSolver_Test/CommonInitData/DataDefaultIteration2/DataDefaultIter2.h"

#include "DataStores/CellNumsGlobalStores/CellNumsGlobalStore.h"
#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsUStore.h"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsUMask.h"


namespace flux_u {

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
    SolverAdjCellGlobalNumsUMask& getAdjCellGlobalNumsUMask();
    SolverFieldsMask& getFieldsMask();

private:
    DataDefaultIter2& dataContainer_;

    CellNumsGlobalStore cellNumsGlobalStore_;
    AdjCellGlobalNumsUStore adjCellGlobalNumsUStore_;
    SolverCellNumsGlobalMask cellNumsGlobalMask_;
    SolverAdjCellGlobalNumsUMask adjCellGlobalNumsUMask_;

    void createCellNumsGlob();
    void createAdjCellGlobalNumsU();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_FLUXU_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H