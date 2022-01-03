#include "CalcedScalars_DefaultIter2.h"

namespace commoninitdata {

CalcedScalars_DefaultIter2::CalcedScalars_DefaultIter2() :  
                            uStarScalar_(uStarData_),
                            vStarScalar_(vStarData_),
                            pPrimeScalar_(pPrimeData_),
                            scalars_(uStarScalar_, 
                                        vStarScalar_, 
                                        pPrimeScalar_) {

}


void CalcedScalars_DefaultIter2::createScalars() {
    createUStar();
    createVStar();
    createPPrime();
}


ScalarsStore& CalcedScalars_DefaultIter2::getScalarsStore() {
    return scalars_;
}


void CalcedScalars_DefaultIter2::createUStar() {
    uStarData_.createVector(cells_u_);

    uStarScalar_.setValue(0  ,     0.000415203 );
    uStarScalar_.setValue(1  ,     0.000432044 );
    uStarScalar_.setValue(2  ,     0.000435838 );
    uStarScalar_.setValue(3  ,      0.00043329 );
    uStarScalar_.setValue(4  ,      1.9469e-05 );
    uStarScalar_.setValue(5  ,     1.12185e-05 );
    uStarScalar_.setValue(6  ,     1.61893e-05 );
    uStarScalar_.setValue(7  ,     3.54425e-05 );
    uStarScalar_.setValue(8  ,     -6.7933e-05 );
    uStarScalar_.setValue(9  ,    -8.65681e-05 );
    uStarScalar_.setValue(10  ,   -8.44096e-05 );
    uStarScalar_.setValue(11  ,   -6.21069e-05 );
    uStarScalar_.setValue(12  ,   -6.47989e-05 );
    uStarScalar_.setValue(13  ,   -8.24791e-05 );
    uStarScalar_.setValue(14  ,   -8.18771e-05 );
    uStarScalar_.setValue(15  ,    -6.3346e-05 );
    uStarScalar_.setValue(16  ,   -3.27677e-05 );
    uStarScalar_.setValue(17  ,   -4.56863e-05 );
    uStarScalar_.setValue(18  ,   -4.55763e-05 );
    uStarScalar_.setValue(19  ,   -3.25405e-05 );
}


void CalcedScalars_DefaultIter2::createVStar() {
    vStarData_.createVector(cells_v_);

    vStarScalar_.setValue(0  ,     0.000116252 );
    vStarScalar_.setValue(1  ,     7.91141e-05 );
    vStarScalar_.setValue(2  ,     3.88288e-06 );
    vStarScalar_.setValue(3  ,    -7.38982e-05 );
    vStarScalar_.setValue(4  ,    -0.000118797 );
    vStarScalar_.setValue(5  ,     9.21453e-05 );
    vStarScalar_.setValue(6  ,     7.22017e-05 );
    vStarScalar_.setValue(7  ,     3.40491e-07 );
    vStarScalar_.setValue(8  ,    -7.20916e-05 );
    vStarScalar_.setValue(9  ,    -9.41053e-05 );
    vStarScalar_.setValue(10  ,    5.51372e-05 );
    vStarScalar_.setValue(11  ,    4.84843e-05 );
    vStarScalar_.setValue(12  ,   -5.85103e-07 );
    vStarScalar_.setValue(13  ,   -4.96157e-05 );
    vStarScalar_.setValue(14  ,   -5.62592e-05 );
    vStarScalar_.setValue(15  ,    2.71603e-05 );
    vStarScalar_.setValue(16  ,    2.71721e-05 );
    vStarScalar_.setValue(17  ,   -5.87672e-07 );
    vStarScalar_.setValue(18  ,   -2.81499e-05 );
    vStarScalar_.setValue(19  ,   -2.76984e-05 );
}

void CalcedScalars_DefaultIter2::createPPrime() {
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