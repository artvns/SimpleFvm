#include "ScalarsStore.h"

namespace fvmsolver {

ScalarsStore::ScalarsStore(
                    CalculatedScalar& uStar, 
                    CalculatedScalar& vStar, 
                    CalculatedScalar& pPime) : 
                                    uStar_(uStar),
                                    vStar_(vStar),
                                    pPime_(pPime) {

}

CalculatedScalar& ScalarsStore::get_uStar() {
    return uStar_;
}

CalculatedScalar& ScalarsStore::get_vStar() {
    return vStar_;
}

CalculatedScalar& ScalarsStore::get_pPrime() {
    return pPime_;
}

}