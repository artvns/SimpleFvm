#include "InitialDataDefaultIter1.h"

namespace rhs_v {

InitialDataDefaultIter1::InitialDataDefaultIter1(
        DataDefaultIter1& dataContainer) : 
                    dataContainer_(dataContainer),
                    cellNumsGlobalMask_(cellNumsGlobalStore_),
                    adjCellGlobalNumsVMask_(adjCellGlobalNumsVStore_) {
                        
    createInitData();
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

double InitialDataDefaultIter1::getSc(size_t i) {
    return Sc_.at(i);
}

double InitialDataDefaultIter1::get_ap(size_t i) {
    return a_p_.at(i);
}

double InitialDataDefaultIter1::getAlpha() {
    return alpha_;
}


void InitialDataDefaultIter1::createInitData() {
    dataContainer_.initializeMeshData();
    dataContainer_.initializeFields();
    createCellNumsGlob();
    createAdjCellGlobalNumsV();
    createVariables();
}


void InitialDataDefaultIter1::createCellNumsGlob() {
    size_t cells_ = 20; 

    cellNumsGlobalStore_.createArrays(cells_);

    cellNumsGlobalStore_.get_pCellNum().setValue(0  ,   7 );
    cellNumsGlobalStore_.get_pCellNum().setValue(1  ,   2 );
    cellNumsGlobalStore_.get_pCellNum().setValue(2  ,   8 );
    cellNumsGlobalStore_.get_pCellNum().setValue(3  ,   3 );
    cellNumsGlobalStore_.get_pCellNum().setValue(4  ,   9 );
    cellNumsGlobalStore_.get_pCellNum().setValue(5  ,   4 );
    cellNumsGlobalStore_.get_pCellNum().setValue(6  ,  12 );
    cellNumsGlobalStore_.get_pCellNum().setValue(7  ,  13 );
    cellNumsGlobalStore_.get_pCellNum().setValue(8  ,  14 );
    cellNumsGlobalStore_.get_pCellNum().setValue(9  ,  17 );
    cellNumsGlobalStore_.get_pCellNum().setValue(10 ,  18 );
    cellNumsGlobalStore_.get_pCellNum().setValue(11 ,  19 );
    cellNumsGlobalStore_.get_pCellNum().setValue(12 ,   6 );
    cellNumsGlobalStore_.get_pCellNum().setValue(13 ,   1 );
    cellNumsGlobalStore_.get_pCellNum().setValue(14 ,  11 );
    cellNumsGlobalStore_.get_pCellNum().setValue(15 ,  16 );
    cellNumsGlobalStore_.get_pCellNum().setValue(16 ,  10 );
    cellNumsGlobalStore_.get_pCellNum().setValue(17 ,   5 );
    cellNumsGlobalStore_.get_pCellNum().setValue(18 ,  15 );
    cellNumsGlobalStore_.get_pCellNum().setValue(19 ,  20 );
}


void InitialDataDefaultIter1::createAdjCellGlobalNumsV() {
    size_t cells_ = 20; 

    adjCellGlobalNumsVStore_.createArrays(cells_);

    adjCellGlobalNumsVStore_.getNumVs().setValue(0  ,  12 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(1  ,   7 ); 
    adjCellGlobalNumsVStore_.getNumVs().setValue(2  ,  13 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(3  ,   8 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(4  ,  14 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(5  ,   9 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(6  ,  17 ); 
    adjCellGlobalNumsVStore_.getNumVs().setValue(7  ,  18 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(8  ,  19 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(9  ,  22 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(10 ,  23 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(11 ,  24 ); 
    adjCellGlobalNumsVStore_.getNumVs().setValue(12 ,  11 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(13 ,   6 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(14 ,  16 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(15 ,  21 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(16 ,  15 ); 
    adjCellGlobalNumsVStore_.getNumVs().setValue(17 ,  10 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(18 ,  20 );
    adjCellGlobalNumsVStore_.getNumVs().setValue(19 ,  25 );
}


void InitialDataDefaultIter1::createVariables() {
    size_t cells_ = 20;

    Sc_.resize(cells_);
    a_p_.resize(cells_);

    Sc_[0]  =  0.0 ;
    Sc_[1]  =  0.0 ;
    Sc_[2]  =  0.0 ;
    Sc_[3]  =  0.0 ;
    Sc_[4]  =  0.0 ;
    Sc_[5]  =  0.0 ;
    Sc_[6]  =  0.0 ;
    Sc_[7]  =  0.0 ;
    Sc_[8]  =  0.0 ;
    Sc_[9]  =  0.0 ;
    Sc_[10] =  0.0 ;
    Sc_[11] =  0.0 ;
    Sc_[12] =  0.0 ;
    Sc_[13] =  0.0 ;
    Sc_[14] =  0.0 ;
    Sc_[15] =  0.0 ;
    Sc_[16] =  0.0 ;
    Sc_[17] =  0.0 ;
    Sc_[18] =  0.0 ;
    Sc_[19] =  0.0 ;

    a_p_[0]  = 0.004016 ;
    a_p_[1]  = 0.003012 ;
    a_p_[2]  = 0.004016 ;
    a_p_[3]  = 0.003012 ;
    a_p_[4]  = 0.004016 ;
    a_p_[5]  = 0.003012 ;
    a_p_[6]  = 0.004016 ;
    a_p_[7]  = 0.004016 ;
    a_p_[8]  = 0.004016 ;
    a_p_[9]  = 0.003012 ;
    a_p_[10] = 0.003012 ;
    a_p_[11] = 0.003012 ;
    a_p_[12] = 0.00502  ;
    a_p_[13] = 0.004016 ;
    a_p_[14] = 0.00502  ;
    a_p_[15] = 0.004016 ;
    a_p_[16] = 0.00502  ;
    a_p_[17] = 0.004016 ;
    a_p_[18] = 0.00502  ;
    a_p_[19] = 0.004016 ;
} 

}