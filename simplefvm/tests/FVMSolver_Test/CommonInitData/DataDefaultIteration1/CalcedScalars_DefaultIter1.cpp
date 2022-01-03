#include "CalcedScalars_DefaultIter1.h"

namespace commoninitdata {

CalcedScalars_DefaultIter1::CalcedScalars_DefaultIter1() :  
                            uStarScalar_(uStarData_),
                            vStarScalar_(vStarData_),
                            pPrimeScalar_(pPrimeData_),
                            scalars_(uStarScalar_, 
                                        vStarScalar_, 
                                        pPrimeScalar_) {

}


void CalcedScalars_DefaultIter1::createScalars() {
    createUStar();
    createVStar();
    createPPrime();
}


ScalarsStore& CalcedScalars_DefaultIter1::getScalarsStore() {
    return scalars_;
}


void CalcedScalars_DefaultIter1::createUStar() {
    uStarData_.createVector(cells_u_);

    uStarScalar_.setValue(0  ,    0.000448887 );
    uStarScalar_.setValue(1  ,    0.000419537 );
    uStarScalar_.setValue(2  ,    0.000419537 );
    uStarScalar_.setValue(3  ,    0.000448887 );
    uStarScalar_.setValue(4  ,     0.00014553 );
    uStarScalar_.setValue(5  ,    0.000128266 );
    uStarScalar_.setValue(6  ,    0.000128266 );
    uStarScalar_.setValue(7  ,     0.00014553 );
    uStarScalar_.setValue(8  ,    4.65462e-05 );
    uStarScalar_.setValue(9  ,    3.96182e-05 );
    uStarScalar_.setValue(10  ,   3.96182e-05 );
    uStarScalar_.setValue(11  ,   4.65462e-05 );
    uStarScalar_.setValue(12  ,   1.43356e-05 );
    uStarScalar_.setValue(13  ,    1.1959e-05 );
    uStarScalar_.setValue(14  ,    1.1959e-05 );
    uStarScalar_.setValue(15  ,   1.43356e-05 );
    uStarScalar_.setValue(16  ,   2.93297e-06 );
    uStarScalar_.setValue(17  ,   2.42427e-06 );
    uStarScalar_.setValue(18  ,   2.42427e-06 );
    uStarScalar_.setValue(19  ,   2.93297e-06 );
}


void CalcedScalars_DefaultIter1::createVStar() {
    vStarData_.createVector(cells_v_);

    vStarScalar_.setValue(0  ,    0.0 );
    vStarScalar_.setValue(1  ,    0.0 );
    vStarScalar_.setValue(2  ,    0.0 );
    vStarScalar_.setValue(3  ,    0.0 );
    vStarScalar_.setValue(4  ,    0.0 );
    vStarScalar_.setValue(5  ,    0.0 );
    vStarScalar_.setValue(6  ,    0.0 );
    vStarScalar_.setValue(7  ,    0.0 );
    vStarScalar_.setValue(8  ,    0.0 );
    vStarScalar_.setValue(9  ,    0.0 );
    vStarScalar_.setValue(10  ,   0.0 );
    vStarScalar_.setValue(11  ,   0.0 );
    vStarScalar_.setValue(12  ,   0.0 );
    vStarScalar_.setValue(13  ,   0.0 );
    vStarScalar_.setValue(14  ,   0.0 );
    vStarScalar_.setValue(15  ,   0.0 );
    vStarScalar_.setValue(16  ,   0.0 );
    vStarScalar_.setValue(17  ,   0.0 );
    vStarScalar_.setValue(18  ,   0.0 );
    vStarScalar_.setValue(19  ,   0.0 );
}

void CalcedScalars_DefaultIter1::createPPrime() {
    pPrimeData_.createVector(cells_p_);

    pPrimeScalar_.setValue(0  ,    0.0 );
    pPrimeScalar_.setValue(1  ,    0.0 );
    pPrimeScalar_.setValue(2  ,    0.0 );
    pPrimeScalar_.setValue(3  ,    0.0 );
    pPrimeScalar_.setValue(4  ,    0.0 );
    pPrimeScalar_.setValue(5  ,    0.0 );
    pPrimeScalar_.setValue(6  ,    0.0 );
    pPrimeScalar_.setValue(7  ,    0.0 );
    pPrimeScalar_.setValue(8  ,    0.0 );
    pPrimeScalar_.setValue(9  ,    0.0 );
    pPrimeScalar_.setValue(10  ,   0.0 );
    pPrimeScalar_.setValue(11  ,   0.0 );
    pPrimeScalar_.setValue(12  ,   0.0 );
    pPrimeScalar_.setValue(13  ,   0.0 );
    pPrimeScalar_.setValue(14  ,   0.0 );
    pPrimeScalar_.setValue(15  ,   0.0 );
    pPrimeScalar_.setValue(16  ,   0.0 );
    pPrimeScalar_.setValue(17  ,   0.0 );
    pPrimeScalar_.setValue(18  ,   0.0 );
    pPrimeScalar_.setValue(19  ,   0.0 );
}

}