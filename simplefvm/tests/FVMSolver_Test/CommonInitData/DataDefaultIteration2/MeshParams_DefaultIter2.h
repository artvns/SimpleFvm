#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_MESHPARAMSDEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_MESHPARAMSDEFAULTITER2_H

#include <cstddef>

#include "DataStores/MeshParametersStores/MeshParametersStore.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"


namespace commoninitdata {

using namespace datastores;


class MeshParams_DefaultIter2 {
public:
    MeshParams_DefaultIter2();

    void createMeshData();
    fvmsolver::SolverMeshParamsMask& getFieldsStoreU();
    fvmsolver::SolverMeshParamsMask& getFieldsStoreV();
    fvmsolver::SolverMeshParamsMask& getFieldsStoreP();

private:
    datastores::MeshParametersStore meshParamsU_;
    datastores::MeshParametersStore meshParamsV_;
    datastores::MeshParametersStore meshParamsP_;

    fvmsolver::SolverMeshParamsMask meshParamsMaskU_;
    fvmsolver::SolverMeshParamsMask meshParamsMaskV_;
    fvmsolver::SolverMeshParamsMask meshParamsMaskP_;

    size_t cells_u_ = 45;
    size_t cells_v_ = 45;
    size_t cells_p_ = 45;

    void createMeshU();
    void createMeshV();
    void createMeshP();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_MESHPARAMSDEFAULTITER2_H