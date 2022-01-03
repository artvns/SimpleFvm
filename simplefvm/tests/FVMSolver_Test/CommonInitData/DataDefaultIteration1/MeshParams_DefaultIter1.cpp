#include "MeshParams_DefaultIter1.h"

namespace commoninitdata {

MeshParams_DefaultIter1::MeshParams_DefaultIter1() :
                meshParamsMaskU_(meshParamsU_),
                meshParamsMaskV_(meshParamsV_),
                meshParamsMaskP_(meshParamsP_) {

}


fvmsolver::SolverMeshParamsMask& MeshParams_DefaultIter1::getFieldsStoreU() {
    return meshParamsMaskU_;
}


fvmsolver::SolverMeshParamsMask& MeshParams_DefaultIter1::getFieldsStoreV() {
    return meshParamsMaskV_;
}


fvmsolver::SolverMeshParamsMask& MeshParams_DefaultIter1::getFieldsStoreP() {
    return meshParamsMaskP_;
}


void MeshParams_DefaultIter1::createMeshData() {
    createMeshU();
    createMeshV();
    createMeshP();
}


void MeshParams_DefaultIter1::createMeshU() {
    meshParamsU_.createArrays(cells_u_);

    for (size_t i = 0; i < cells_u_; i++) {
        meshParamsU_.get_dX().setValue(i, 0.001 );
        meshParamsU_.get_dY().setValue(i, 0.001 );
    }
}


void MeshParams_DefaultIter1::createMeshV() {
    meshParamsV_.createArrays(cells_v_);

    for (size_t i = 0; i < cells_v_; i++) {
        meshParamsV_.get_dX().setValue(i, 0.001 );
        meshParamsV_.get_dY().setValue(i, 0.001 );
    } 
}


void MeshParams_DefaultIter1::createMeshP() {
    meshParamsP_.createArrays(cells_p_);

    for (size_t i = 0; i < cells_p_; i++) {
        meshParamsP_.get_dX().setValue(i, 0.001 );
        meshParamsP_.get_dY().setValue(i, 0.001 );
    } 
}

}