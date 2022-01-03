#include "InitialDataDefaultIter1.h"

namespace rhs_u {

InitialDataDefaultIter1::InitialDataDefaultIter1(
        DataDefaultIter1& dataContainer) : 
                    dataContainer_(dataContainer),
                    cellNumsGlobalMask_(cellNumsGlobalStore_),
                    adjCellGlobalNumsUMask_(adjCellGlobalNumsUStore_) {
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

SolverAdjCellGlobalNumsUMask& InitialDataDefaultIter1::getAdjCellGlobalNumsUMask() {
    return adjCellGlobalNumsUMask_;
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
    createAdjCellGlobalNumsU();
    createVariables();
}


void InitialDataDefaultIter1::createCellNumsGlob() {
    size_t cells_ = 20; 

    cellNumsGlobalStore_.createArrays(cells_);

    cellNumsGlobalStore_.get_pCellNum().setValue(0  ,   7 );
    cellNumsGlobalStore_.get_pCellNum().setValue(1  ,   8 );
    cellNumsGlobalStore_.get_pCellNum().setValue(2  ,   9 );
    cellNumsGlobalStore_.get_pCellNum().setValue(3  ,  10 );
    cellNumsGlobalStore_.get_pCellNum().setValue(4  ,  12 );
    cellNumsGlobalStore_.get_pCellNum().setValue(5  ,  13 );
    cellNumsGlobalStore_.get_pCellNum().setValue(6  ,  14 );
    cellNumsGlobalStore_.get_pCellNum().setValue(7  ,  15 );
    cellNumsGlobalStore_.get_pCellNum().setValue(8  ,  17 );
    cellNumsGlobalStore_.get_pCellNum().setValue(9  ,  18 );
    cellNumsGlobalStore_.get_pCellNum().setValue(10 ,  19 );
    cellNumsGlobalStore_.get_pCellNum().setValue(11 ,  20 );
    cellNumsGlobalStore_.get_pCellNum().setValue(12 ,   2 );
    cellNumsGlobalStore_.get_pCellNum().setValue(13 ,   3 );
    cellNumsGlobalStore_.get_pCellNum().setValue(14 ,   4 );
    cellNumsGlobalStore_.get_pCellNum().setValue(15 ,   5 );
    cellNumsGlobalStore_.get_pCellNum().setValue(16 ,  22 );
    cellNumsGlobalStore_.get_pCellNum().setValue(17 ,  23 );
    cellNumsGlobalStore_.get_pCellNum().setValue(18 ,  24 );
    cellNumsGlobalStore_.get_pCellNum().setValue(19 ,  25 );
}


void InitialDataDefaultIter1::createAdjCellGlobalNumsU() {
    size_t cells_ = 20; 

    adjCellGlobalNumsUStore_.createArrays(cells_);

    adjCellGlobalNumsUStore_.getNumUw().setValue(0  ,   6 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(1  ,   7 ); 
    adjCellGlobalNumsUStore_.getNumUw().setValue(2  ,   8 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(3  ,   9 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(4  ,  11 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(5  ,  12 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(6  ,  13 ); 
    adjCellGlobalNumsUStore_.getNumUw().setValue(7  ,  14 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(8  ,  16 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(9  ,  17 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(10 ,  18 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(11 ,  19 ); 
    adjCellGlobalNumsUStore_.getNumUw().setValue(12 ,   1 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(13 ,   2 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(14 ,   3 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(15 ,   4 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(16 ,  21 ); 
    adjCellGlobalNumsUStore_.getNumUw().setValue(17 ,  22 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(18 ,  23 );
    adjCellGlobalNumsUStore_.getNumUw().setValue(19 ,  24 );
}


void InitialDataDefaultIter1::createVariables() {
    size_t cells_ = 20;

    Sc_.resize(cells_);
    a_p_.resize(cells_);

    Sc_[0]  =        0.0 ;
    Sc_[1]  =        0.0 ;
    Sc_[2]  =        0.0 ;
    Sc_[3]  =        0.0 ;
    Sc_[4]  =        0.0 ;
    Sc_[5]  =        0.0 ;
    Sc_[6]  =        0.0 ;
    Sc_[7]  =        0.0 ;
    Sc_[8]  =        0.0 ;
    Sc_[9]  =        0.0 ;
    Sc_[10] =        0.0 ;
    Sc_[11] =        0.0 ;
    Sc_[12] =  2.008e-06 ;
    Sc_[13] =  2.008e-06 ;
    Sc_[14] =  2.008e-06 ;
    Sc_[15] =  2.008e-06 ;
    Sc_[16] =        0.0 ;
    Sc_[17] =        0.0 ;
    Sc_[18] =        0.0 ;
    Sc_[19] =        0.0 ;

    a_p_[0]  = 0.003012 ;
    a_p_[1]  = 0.004016 ;
    a_p_[2]  = 0.004016 ;
    a_p_[3]  = 0.003012 ;
    a_p_[4]  = 0.003012 ;
    a_p_[5]  = 0.004016 ;
    a_p_[6]  = 0.004016 ;
    a_p_[7]  = 0.003012 ;
    a_p_[8]  = 0.003012 ;
    a_p_[9]  = 0.004016 ;
    a_p_[10] = 0.004016 ;
    a_p_[11] = 0.003012 ;
    a_p_[12] = 0.004016 ;
    a_p_[13] = 0.00502  ;
    a_p_[14] = 0.00502  ;
    a_p_[15] = 0.004016 ;
    a_p_[16] = 0.004016 ;
    a_p_[17] = 0.00502  ;
    a_p_[18] = 0.00502  ;
    a_p_[19] = 0.004016 ;
} 

}