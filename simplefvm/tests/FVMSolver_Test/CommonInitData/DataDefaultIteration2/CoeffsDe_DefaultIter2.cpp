#include "CoeffsDe_DefaultIter2.h"

namespace commoninitdata {

CoeffsDe_DefaultIter2::CoeffsDe_DefaultIter2() {

}


CoeffsCalculatorsStore& CoeffsDe_DefaultIter2::getCoeffsCalculatorsStore() {
    return coeffsCalculators_;
}


void CoeffsDe_DefaultIter2::createCoeffsCalculators() {
    coeffsCalculators_.createArrays(cells_u_, cells_v_);
    createDeU();
    createDeV();
}


void CoeffsDe_DefaultIter2::createDeU() {
    coeffsCalculators_.set_deU(0  ,    0.175715 );
    coeffsCalculators_.set_deU(1  ,    0.139503 );
    coeffsCalculators_.set_deU(2  ,    0.139381 );
    coeffsCalculators_.set_deU(3  ,    0.172913 );
    coeffsCalculators_.set_deU(4  ,    0.231737 );
    coeffsCalculators_.set_deU(5  ,    0.174359 );
    coeffsCalculators_.set_deU(6  ,    0.174247 );
    coeffsCalculators_.set_deU(7  ,    0.233075 );
    coeffsCalculators_.set_deU(8  ,    0.231737 );
    coeffsCalculators_.set_deU(9  ,    0.174325 );
    coeffsCalculators_.set_deU(10  ,    0.17428 );
    coeffsCalculators_.set_deU(11  ,   0.233074 );
    coeffsCalculators_.set_deU(12  ,   0.231914 );
    coeffsCalculators_.set_deU(13  ,   0.174311 );
    coeffsCalculators_.set_deU(14  ,   0.174295 );
    coeffsCalculators_.set_deU(15  ,   0.232896 );
    coeffsCalculators_.set_deU(16  ,   0.174114 );
    coeffsCalculators_.set_deU(17  ,   0.139443 );
    coeffsCalculators_.set_deU(18  ,   0.139441 );
    coeffsCalculators_.set_deU(19  ,   0.174492 );
}


void CoeffsDe_DefaultIter2::createDeV() {
    coeffsCalculators_.set_deV(0  ,    0.171125 );
    coeffsCalculators_.set_deV(1  ,     0.23182 );
    coeffsCalculators_.set_deV(2  ,    0.232404 );
    coeffsCalculators_.set_deV(3  ,    0.232991 );
    coeffsCalculators_.set_deV(4  ,    0.177601 );
    coeffsCalculators_.set_deV(5  ,    0.139044 );
    coeffsCalculators_.set_deV(6  ,    0.174381 );
    coeffsCalculators_.set_deV(7  ,    0.174303 );
    coeffsCalculators_.set_deV(8  ,    0.174224 );
    coeffsCalculators_.set_deV(9  ,    0.139843 );
    coeffsCalculators_.set_deV(10  ,   0.139316 );
    coeffsCalculators_.set_deV(11  ,   0.174333 );
    coeffsCalculators_.set_deV(12  ,   0.174303 );
    coeffsCalculators_.set_deV(13  ,   0.174273 );
    coeffsCalculators_.set_deV(14  ,   0.139569 );
    coeffsCalculators_.set_deV(15  ,   0.174438 );
    coeffsCalculators_.set_deV(16  ,    0.23268 );
    coeffsCalculators_.set_deV(17  ,   0.232404 );
    coeffsCalculators_.set_deV(18  ,   0.232128 );
    coeffsCalculators_.set_deV(19  ,   0.174168 );
}

}