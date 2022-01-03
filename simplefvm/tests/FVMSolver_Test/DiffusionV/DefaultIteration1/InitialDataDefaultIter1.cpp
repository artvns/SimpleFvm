#include "InitialDataDefaultIter1.h"

namespace diffusion_v {

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
    
    return dataContainer_.getMeshParams().getFieldsStoreV();
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

    cellNumsGlobalStore_.get_pCellNum().setValue(0,   7   );
    cellNumsGlobalStore_.get_pCellNum().setValue(1,   2   ); 
    cellNumsGlobalStore_.get_pCellNum().setValue(2,   8   );
    cellNumsGlobalStore_.get_pCellNum().setValue(3,   3   );
    cellNumsGlobalStore_.get_pCellNum().setValue(4,   9   );
    cellNumsGlobalStore_.get_pCellNum().setValue(5,   4   );
    cellNumsGlobalStore_.get_pCellNum().setValue(6,   12  );
    cellNumsGlobalStore_.get_pCellNum().setValue(7,   13  );
    cellNumsGlobalStore_.get_pCellNum().setValue(8,   14  );
    cellNumsGlobalStore_.get_pCellNum().setValue(9,   17  );
    cellNumsGlobalStore_.get_pCellNum().setValue(10,  18  );
    cellNumsGlobalStore_.get_pCellNum().setValue(11,  19  );
    cellNumsGlobalStore_.get_pCellNum().setValue(12,  6   );
    cellNumsGlobalStore_.get_pCellNum().setValue(13,  1   ); 
    cellNumsGlobalStore_.get_pCellNum().setValue(14,  11  );
    cellNumsGlobalStore_.get_pCellNum().setValue(15,  16  );
    cellNumsGlobalStore_.get_pCellNum().setValue(16,  10  );
    cellNumsGlobalStore_.get_pCellNum().setValue(17,  5   );
    cellNumsGlobalStore_.get_pCellNum().setValue(18,  15  );
    cellNumsGlobalStore_.get_pCellNum().setValue(19,  20  );
}

}