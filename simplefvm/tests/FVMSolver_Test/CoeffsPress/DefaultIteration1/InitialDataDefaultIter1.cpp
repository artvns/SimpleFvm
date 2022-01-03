#include "InitialDataDefaultIter1.h"

namespace coeffs_p {

InitialDataDefaultIter1::InitialDataDefaultIter1(
        DataDefaultIter1& dataContainer) : 
                    dataContainer_(dataContainer),
                    cellNumsGlobalMask_(cellNumsGlobalStore_),
                    adjCellInteriorNumsPMask_(adjCellInteriorNumsPStore_) {
    createInitData();
}


SolverFluidPropsMask& InitialDataDefaultIter1::getFluidPropertiesMask() {
    return dataContainer_.getFluidProps().getFluidPropertiesStore();
}

SolverMeshParamsMask& InitialDataDefaultIter1::getMeshParametersMask() {
    
    return dataContainer_.getMeshParams().getFieldsStoreP();
}

SolverCellNumsGlobalMask& InitialDataDefaultIter1::getCellNumsGlobalMask() {
    return cellNumsGlobalMask_;
}

SolverAdjCellInteriorNumsPMask& InitialDataDefaultIter1::getAdjCellInteriorNumsPMask() {
    return adjCellInteriorNumsPMask_;
}

CoeffsCalculatorsStore& InitialDataDefaultIter1::getCoeffsCalculatorsStore() {
    return dataContainer_.getCoeffsDeIterations().getCoeffsCalculatorsStore();
}


void InitialDataDefaultIter1::createInitData() {
    dataContainer_.initializeFluid();
    dataContainer_.initializeMeshData();
    dataContainer_.initializeCoeffs_de();

    createCellNumsGlob();
    createAdjCellNumsInterior();
}


void InitialDataDefaultIter1::createCellNumsGlob() {
    size_t cells_ = 6; 

    cellNumsGlobalStore_.createArrays(cells_);

    cellNumsGlobalStore_.get_pCellNum().setValue(0,  7 );
    cellNumsGlobalStore_.get_pCellNum().setValue(1,  8 );
    cellNumsGlobalStore_.get_pCellNum().setValue(2,  9 );
    cellNumsGlobalStore_.get_pCellNum().setValue(3, 12 );
    cellNumsGlobalStore_.get_pCellNum().setValue(4, 13 );
    cellNumsGlobalStore_.get_pCellNum().setValue(5, 14 );
}


void InitialDataDefaultIter1::createAdjCellNumsInterior() {
    size_t cells_ = 6;

    adjCellInteriorNumsPStore_.createArrays(cells_);

    adjCellInteriorNumsPStore_.get_numUStarW().setValue(0,  5 );
    adjCellInteriorNumsPStore_.get_numUStarW().setValue(1,  6 ); 
    adjCellInteriorNumsPStore_.get_numUStarW().setValue(2,  7 );
    adjCellInteriorNumsPStore_.get_numUStarW().setValue(3,  9 );
    adjCellInteriorNumsPStore_.get_numUStarW().setValue(4, 10 );
    adjCellInteriorNumsPStore_.get_numUStarW().setValue(5, 11 );

    adjCellInteriorNumsPStore_.get_numUStarE().setValue(0,  6 );
    adjCellInteriorNumsPStore_.get_numUStarE().setValue(1,  7 ); 
    adjCellInteriorNumsPStore_.get_numUStarE().setValue(2,  8 );
    adjCellInteriorNumsPStore_.get_numUStarE().setValue(3, 10 );
    adjCellInteriorNumsPStore_.get_numUStarE().setValue(4, 11 );
    adjCellInteriorNumsPStore_.get_numUStarE().setValue(5, 12 );

    adjCellInteriorNumsPStore_.get_numVStarN().setValue(0,  2 );
    adjCellInteriorNumsPStore_.get_numVStarN().setValue(1,  3 ); 
    adjCellInteriorNumsPStore_.get_numVStarN().setValue(2,  4 );
    adjCellInteriorNumsPStore_.get_numVStarN().setValue(3,  7 );
    adjCellInteriorNumsPStore_.get_numVStarN().setValue(4,  8 );
    adjCellInteriorNumsPStore_.get_numVStarN().setValue(5,  9 );

    adjCellInteriorNumsPStore_.get_numVStarS().setValue(0,  7 );
    adjCellInteriorNumsPStore_.get_numVStarS().setValue(1,  8 ); 
    adjCellInteriorNumsPStore_.get_numVStarS().setValue(2,  9 );
    adjCellInteriorNumsPStore_.get_numVStarS().setValue(3, 12 );
    adjCellInteriorNumsPStore_.get_numVStarS().setValue(4, 13 );
    adjCellInteriorNumsPStore_.get_numVStarS().setValue(5, 14 );
}

}