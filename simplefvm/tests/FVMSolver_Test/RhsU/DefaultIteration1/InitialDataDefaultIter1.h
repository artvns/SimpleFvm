#ifndef SIMPLEFVM_FVMSOLVERTEST_RHSU_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_RHSU_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H

#include <cstddef>

#include "FVMSolver_Test/CommonInitData/CommonData.h"
#include "FVMSolver_Test/CommonInitData/DataDefaultIteration1/DataDefaultIter1.h"

#include "DataStores/CellNumsGlobalStores/CellNumsGlobalStore.h"
#include "DataStores/AdjCellNumsGlobalStores/AdjCellGlobalNumsUStore.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsUMask.h"


namespace rhs_u {

using namespace fvmsolver;
using namespace datastores;
using namespace commoninitdata;


class InitialDataDefaultIter1 {
public:
    InitialDataDefaultIter1(DataDefaultIter1& dataContainer);

    void createInitData();

    double getSc(size_t i);
    double get_ap(size_t i);
    double getAlpha();

    SolverMeshParamsMask& getMeshParametersMask();
    SolverCellNumsGlobalMask& getCellNumsGlobalMask();
    SolverAdjCellGlobalNumsUMask& getAdjCellGlobalNumsUMask();
    SolverFieldsMask& getFieldsMask();

private:
    DataDefaultIter1& dataContainer_;

    CellNumsGlobalStore cellNumsGlobalStore_;
    AdjCellGlobalNumsUStore adjCellGlobalNumsUStore_;
    SolverCellNumsGlobalMask cellNumsGlobalMask_;
    SolverAdjCellGlobalNumsUMask adjCellGlobalNumsUMask_;

    std::vector<double> Sc_;
    std::vector<double> a_p_;

    double alpha_ = 0.7;

    void createCellNumsGlob();
    void createAdjCellGlobalNumsU();

    void createVariables();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_RHSU_DEFAULTITERATION1_INITIALDATADEFAULTITER1_H