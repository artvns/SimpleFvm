#include "InitialDataDefaultIter1.h"

namespace flux_v {

InitialDataDefaultIter1::InitialDataDefaultIter1(
        DataDefaultIter1& dataContainer) : 
                    dataContainer_(dataContainer),
                    cellNumsGlobalMask_(cellNumsGlobalStore_),
                    adjCellGlobalNumsVMask_(adjCellGlobalNumsVStore_) {
    createInitData();
}


SolverFluidPropsMask& InitialDataDefaultIter1::getFluidPropertiesMask() {
    return dataContainer_.getFluidProps().getFluidPropertiesStore();
}

SolverMeshParamsMask& InitialDataDefaultIter1::getMeshParametersMask() {
    
    return dataContainer_.getMeshParams().getFieldsStoreU();
}

SolverFieldsMask& InitialDataDefaultIter1::getFieldsMask() {
    return dataContainer_.getFieldsIterations().getFieldsMask();
}

SolverCellNumsGlobalMask& InitialDataDefaultIter1::getCellNumsGlobalMask() {
    return cellNumsGlobalMask_;
}

SolverAdjCellGlobalNumsVMask& InitialDataDefaultIter1::getAdjCellGlobalNumsVMask() {
    return adjCellGlobalNumsVMask_;
}


void InitialDataDefaultIter1::createInitData() {
    dataContainer_.initializeFluid();
    dataContainer_.initializeMeshData();
    dataContainer_.initializeFields();
    createCellNumsGlob();
    createAdjCellGlobalNumsV();
}


void InitialDataDefaultIter1::createCellNumsGlob() {
    size_t cells_ = 6; 

    cellNumsGlobalStore_.createArrays(cells_);

    cellNumsGlobalStore_.get_pCellNum().setValue(0,   7 );
    cellNumsGlobalStore_.get_pCellNum().setValue(1,   2 );
    cellNumsGlobalStore_.get_pCellNum().setValue(2,   8 );
    cellNumsGlobalStore_.get_pCellNum().setValue(3,   3 );
    cellNumsGlobalStore_.get_pCellNum().setValue(4,   9 );
    cellNumsGlobalStore_.get_pCellNum().setValue(5,   4 );
}


void InitialDataDefaultIter1::createAdjCellGlobalNumsV() {
    size_t cells_ = 6; 

    adjCellGlobalNumsVStore_.createArrays(cells_);

    adjCellGlobalNumsVStore_.getNumVn().setValue(0,  2  );
    adjCellGlobalNumsVStore_.getNumVn().setValue(1,  28 ); 
    adjCellGlobalNumsVStore_.getNumVn().setValue(2,  3  );
    adjCellGlobalNumsVStore_.getNumVn().setValue(3,  29 );
    adjCellGlobalNumsVStore_.getNumVn().setValue(4,  4  );
    adjCellGlobalNumsVStore_.getNumVn().setValue(5,  30 );

    adjCellGlobalNumsVStore_.getNumVs().setValue(0,  12 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(1,   7 ); 
    adjCellGlobalNumsVStore_.getNumVs().setValue(2,  13 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(3,   8 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(4,  14 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(5,   9 );

    adjCellGlobalNumsVStore_.getNumUwn().setValue(0,  7  );
    adjCellGlobalNumsVStore_.getNumUwn().setValue(1,  2  );
    adjCellGlobalNumsVStore_.getNumUwn().setValue(2,  8  );
    adjCellGlobalNumsVStore_.getNumUwn().setValue(3,  3  );
    adjCellGlobalNumsVStore_.getNumUwn().setValue(4,  9  );
    adjCellGlobalNumsVStore_.getNumUwn().setValue(5,  4  );

    adjCellGlobalNumsVStore_.getNumUws().setValue(0,  12 );
    adjCellGlobalNumsVStore_.getNumUws().setValue(1,  7  );
    adjCellGlobalNumsVStore_.getNumUws().setValue(2,  13 );
    adjCellGlobalNumsVStore_.getNumUws().setValue(3,  8  );
    adjCellGlobalNumsVStore_.getNumUws().setValue(4,  14 );
    adjCellGlobalNumsVStore_.getNumUws().setValue(5,  9  );

    adjCellGlobalNumsVStore_.getNumUen().setValue(0,  8  );
    adjCellGlobalNumsVStore_.getNumUen().setValue(1,  3  );
    adjCellGlobalNumsVStore_.getNumUen().setValue(2,  9  );
    adjCellGlobalNumsVStore_.getNumUen().setValue(3,  4  );
    adjCellGlobalNumsVStore_.getNumUen().setValue(4,  10 );
    adjCellGlobalNumsVStore_.getNumUen().setValue(5,  5  );

    adjCellGlobalNumsVStore_.getNumUes().setValue(0,  13 );
    adjCellGlobalNumsVStore_.getNumUes().setValue(1,  8  );
    adjCellGlobalNumsVStore_.getNumUes().setValue(2,  14 );
    adjCellGlobalNumsVStore_.getNumUes().setValue(3,  9  );
    adjCellGlobalNumsVStore_.getNumUes().setValue(4,  15 );
    adjCellGlobalNumsVStore_.getNumUes().setValue(5,  10 );
}

}