#ifndef SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONV_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONV_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H

#include <cstddef>

#include "FVMSolver_Test/CommonInitData/CommonData.h"
#include "FVMSolver_Test/CommonInitData/DataDefaultIteration2/DataDefaultIter2.h"

#include "DataStores/CellNumsGlobalStores/CellNumsGlobalStore.h"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"


namespace diffusion_v {

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

private:
    DataDefaultIter2& dataContainer_;

    CellNumsGlobalStore cellNumsGlobalStore_;
    SolverCellNumsGlobalMask cellNumsGlobalMask_;

    void createCellNumsGlob();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONV_DEFAULTITERATION2_INITIALDATADEFAULTITER2_H