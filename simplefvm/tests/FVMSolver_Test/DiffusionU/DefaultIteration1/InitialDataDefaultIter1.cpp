#include "InitialDataDefaultIter1.h"

namespace diffusion_u {

InitialDataDefaultIter1::InitialDataDefaultIter1(
        DataDefaultIter1& dataContainer) : 
                    dataContainer_(dataContainer),
                    cellNumsGlobalMask_(cellNumsGlobalStore_) {
    createInitData();
}


SolverFluidPropsMask& InitialDataDefaultIter1::getFluidPropertiesMask() {
    return dataContainer_.getFluidProps().getFluidPropertiesStore();
}

SolverMeshParamsMask& InitialDataDefaultIter1::getMeshParametersMask() {
    
    return dataContainer_.getMeshParams().getFieldsStoreU();
}

SolverCellNumsGlobalMask& InitialDataDefaultIter1::getCellNumsGlobalMask() {
    return cellNumsGlobalMask_;
}


void InitialDataDefaultIter1::createInitData() {
    dataContainer_.initializeFluid();
    dataContainer_.initializeMeshData();
    createCellNumsGlob();
}


void InitialDataDefaultIter1::createCellNumsGlob() {
    size_t cells_ = 20; 

    cellNumsGlobalStore_.createArrays(cells_);

    cellNumsGlobalStore_.get_pCellNum().setValue(0, 7);
    cellNumsGlobalStore_.get_pCellNum().setValue(1, 8);
    cellNumsGlobalStore_.get_pCellNum().setValue(2, 9);
    cellNumsGlobalStore_.get_pCellNum().setValue(3, 10);
    cellNumsGlobalStore_.get_pCellNum().setValue(4, 12);
    cellNumsGlobalStore_.get_pCellNum().setValue(5, 13);
    cellNumsGlobalStore_.get_pCellNum().setValue(6, 14);
    cellNumsGlobalStore_.get_pCellNum().setValue(7, 15);
    cellNumsGlobalStore_.get_pCellNum().setValue(8, 17);
    cellNumsGlobalStore_.get_pCellNum().setValue(9, 18);
    cellNumsGlobalStore_.get_pCellNum().setValue(10, 19);
    cellNumsGlobalStore_.get_pCellNum().setValue(11, 20);
    cellNumsGlobalStore_.get_pCellNum().setValue(12, 2);
    cellNumsGlobalStore_.get_pCellNum().setValue(13, 3);
    cellNumsGlobalStore_.get_pCellNum().setValue(14, 4);
    cellNumsGlobalStore_.get_pCellNum().setValue(15, 5);
    cellNumsGlobalStore_.get_pCellNum().setValue(16, 22);
    cellNumsGlobalStore_.get_pCellNum().setValue(17, 23);
    cellNumsGlobalStore_.get_pCellNum().setValue(18, 24);
    cellNumsGlobalStore_.get_pCellNum().setValue(19, 25);
}

}