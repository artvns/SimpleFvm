#ifndef SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONU_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONU_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H

#include <cstddef>

#include "FVMSolver_Test/CommonInitData/CommonData.h"
#include "FVMSolver_Test/CommonInitData/DataDefaultIteration1/DataDefaultIter1.h"

#include "DataStores/CellNumsGlobalStores/CellNumsGlobalStore.h"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"


namespace diffusion_u {

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

private:
    DataDefaultIter1& dataContainer_;

    CellNumsGlobalStore cellNumsGlobalStore_;
    SolverCellNumsGlobalMask cellNumsGlobalMask_;

    void createCellNumsGlob();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONU_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H