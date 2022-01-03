#include "CoeffsDe_DefaultIter1.h"

namespace commoninitdata {

CoeffsDe_DefaultIter1::CoeffsDe_DefaultIter1() {

}


CoeffsCalculatorsStore& CoeffsDe_DefaultIter1::getCoeffsCalculatorsStore() {
    return coeffsCalculators_;
}


void CoeffsDe_DefaultIter1::createCoeffsCalculators() {
    coeffsCalculators_.createArrays(cells_u_, cells_v_);
    createDeU();
    createDeV();
}


void CoeffsDe_DefaultIter1::createDeU() {
    coeffsCalculators_.set_deU(0  ,    0.174303 );
    coeffsCalculators_.set_deU(1  ,    0.139442 );
    coeffsCalculators_.set_deU(2  ,    0.139442 );
    coeffsCalculators_.set_deU(3  ,    0.174303 );
    coeffsCalculators_.set_deU(4  ,    0.232404 );
    coeffsCalculators_.set_deU(5  ,    0.174303 );
    coeffsCalculators_.set_deU(6  ,    0.174303 );
    coeffsCalculators_.set_deU(7  ,    0.232404 );
    coeffsCalculators_.set_deU(8  ,    0.232404 );
    coeffsCalculators_.set_deU(9  ,    0.174303 );
    coeffsCalculators_.set_deU(10  ,   0.174303 );
    coeffsCalculators_.set_deU(11  ,   0.232404 );
    coeffsCalculators_.set_deU(12  ,   0.232404 );
    coeffsCalculators_.set_deU(13  ,   0.174303 );
    coeffsCalculators_.set_deU(14  ,   0.174303 );
    coeffsCalculators_.set_deU(15  ,   0.232404 );
    coeffsCalculators_.set_deU(16  ,   0.174303 );
    coeffsCalculators_.set_deU(17  ,   0.139442 );
    coeffsCalculators_.set_deU(18  ,   0.139442 );
    coeffsCalculators_.set_deU(19  ,   0.174303 );
}


void CoeffsDe_DefaultIter1::createDeV() {
    coeffsCalculators_.set_deV(0  ,    0.174303 );
    coeffsCalculators_.set_deV(1  ,    0.232404 );
    coeffsCalculators_.set_deV(2  ,    0.232404 );
    coeffsCalculators_.set_deV(3  ,    0.232404 );
    coeffsCalculators_.set_deV(4  ,    0.174303 );
    coeffsCalculators_.set_deV(5  ,    0.139442 );
    coeffsCalculators_.set_deV(6  ,    0.174303 );
    coeffsCalculators_.set_deV(7  ,    0.174303 );
    coeffsCalculators_.set_deV(8  ,    0.174303 );
    coeffsCalculators_.set_deV(9  ,    0.139442 );
    coeffsCalculators_.set_deV(10  ,   0.139442 );
    coeffsCalculators_.set_deV(11  ,   0.174303 );
    coeffsCalculators_.set_deV(12  ,   0.174303 );
    coeffsCalculators_.set_deV(13  ,   0.174303 );
    coeffsCalculators_.set_deV(14  ,   0.139442 );
    coeffsCalculators_.set_deV(15  ,   0.174303 );
    coeffsCalculators_.set_deV(16  ,   0.232404 );
    coeffsCalculators_.set_deV(17  ,   0.232404 );
    coeffsCalculators_.set_deV(18  ,   0.232404 );
    coeffsCalculators_.set_deV(19  ,   0.174303 );
}

}