#include "InitialDataDefaultIter2.h"

namespace flux_u {

InitialDataDefaultIter2::InitialDataDefaultIter2(
        DataDefaultIter2& dataContainer) : 
                    dataContainer_(dataContainer),
                    cellNumsGlobalMask_(cellNumsGlobalStore_),
                    adjCellGlobalNumsUMask_(adjCellGlobalNumsUStore_) {
    createInitData();
}


SolverFluidPropsMask& InitialDataDefaultIter2::getFluidPropertiesMask() {
    return dataContainer_.getFluidProps().getFluidPropertiesStore();
}

SolverMeshParamsMask& InitialDataDefaultIter2::getMeshParametersMask() {
    
    return dataContainer_.getMeshParams().getFieldsStoreU();
}

SolverFieldsMask& InitialDataDefaultIter2::getFieldsMask() {
    return dataContainer_.getFieldsIterations().getFieldsMask();
}

SolverCellNumsGlobalMask& InitialDataDefaultIter2::getCellNumsGlobalMask() {
    return cellNumsGlobalMask_;
}

SolverAdjCellGlobalNumsUMask& InitialDataDefaultIter2::getAdjCellGlobalNumsUMask() {
    return adjCellGlobalNumsUMask_;
}


void InitialDataDefaultIter2::createInitData() {
    dataContainer_.initializeFluid();
    dataContainer_.initializeMeshData();
    dataContainer_.initializeFields();
    createCellNumsGlob();
    createAdjCellGlobalNumsU();
}


void InitialDataDefaultIter2::createCellNumsGlob() {
    size_t cells_ = 6; 

    cellNumsGlobalStore_.createArrays(cells_);

    cellNumsGlobalStore_.get_pCellNum().setValue(0,   7  );
    cellNumsGlobalStore_.get_pCellNum().setValue(1,   8  );
    cellNumsGlobalStore_.get_pCellNum().setValue(2,   9  );
    cellNumsGlobalStore_.get_pCellNum().setValue(3,   10 );
    cellNumsGlobalStore_.get_pCellNum().setValue(4,   12 );
    cellNumsGlobalStore_.get_pCellNum().setValue(5,   13 );
}


void InitialDataDefaultIter2::createAdjCellGlobalNumsU() {
    size_t cells_ = 6; 

    adjCellGlobalNumsUStore_.createArrays(cells_);

    adjCellGlobalNumsUStore_.getNumUw().setValue(0,  6  );
    adjCellGlobalNumsUStore_.getNumUw().setValue(1,  7  ); 
    adjCellGlobalNumsUStore_.getNumUw().setValue(2,  8  );
    adjCellGlobalNumsUStore_.getNumUw().setValue(3,  9  );
    adjCellGlobalNumsUStore_.getNumUw().setValue(4,  11 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(5,  12 );

    adjCellGlobalNumsUStore_.getNumUe().setValue(0,  8  );
    adjCellGlobalNumsUStore_.getNumUe().setValue(1,  9  ); 
    adjCellGlobalNumsUStore_.getNumUe().setValue(2,  10 );
    adjCellGlobalNumsUStore_.getNumUe().setValue(3,  34 );
    adjCellGlobalNumsUStore_.getNumUe().setValue(4,  13 );
    adjCellGlobalNumsUStore_.getNumUe().setValue(5,  14 );


    adjCellGlobalNumsUStore_.getNumVnw().setValue(0,  1  );
    adjCellGlobalNumsUStore_.getNumVnw().setValue(1,  2  );
    adjCellGlobalNumsUStore_.getNumVnw().setValue(2,  3  );
    adjCellGlobalNumsUStore_.getNumVnw().setValue(3,  4  );
    adjCellGlobalNumsUStore_.getNumVnw().setValue(4,  6  );
    adjCellGlobalNumsUStore_.getNumVnw().setValue(5,  7  );

    adjCellGlobalNumsUStore_.getNumVne().setValue(0,  2  );
    adjCellGlobalNumsUStore_.getNumVne().setValue(1,  3  );
    adjCellGlobalNumsUStore_.getNumVne().setValue(2,  4  );
    adjCellGlobalNumsUStore_.getNumVne().setValue(3,  5  );
    adjCellGlobalNumsUStore_.getNumVne().setValue(4,  7  );
    adjCellGlobalNumsUStore_.getNumVne().setValue(5,  8  );

    adjCellGlobalNumsUStore_.getNumVsw().setValue(0,  6  );
    adjCellGlobalNumsUStore_.getNumVsw().setValue(1,  7  );
    adjCellGlobalNumsUStore_.getNumVsw().setValue(2,  8  );
    adjCellGlobalNumsUStore_.getNumVsw().setValue(3,  9  );
    adjCellGlobalNumsUStore_.getNumVsw().setValue(4,  11 );
    adjCellGlobalNumsUStore_.getNumVsw().setValue(5,  12 );

    adjCellGlobalNumsUStore_.getNumVse().setValue(0,   7 );
    adjCellGlobalNumsUStore_.getNumVse().setValue(1,   8 );
    adjCellGlobalNumsUStore_.getNumVse().setValue(2,   9 );
    adjCellGlobalNumsUStore_.getNumVse().setValue(3,  10 );
    adjCellGlobalNumsUStore_.getNumVse().setValue(4,  12 );
    adjCellGlobalNumsUStore_.getNumVse().setValue(5,  13 );
}

}