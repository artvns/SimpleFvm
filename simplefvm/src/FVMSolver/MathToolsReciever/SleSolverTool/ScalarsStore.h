#ifndef SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_SCALARSSTORE_H
#define SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_SCALARSSTORE_H

#include "CalculatedScalar.h"

namespace fvmsolver {

class ScalarsStore {
public:
    ScalarsStore(CalculatedScalar& uStar, 
                    CalculatedScalar& vStar, 
                    CalculatedScalar& pPime);

    CalculatedScalar& get_uStar();
    CalculatedScalar& get_vStar();
    CalculatedScalar& get_pPrime();

private:
    CalculatedScalar& uStar_;
    CalculatedScalar& vStar_;
    CalculatedScalar& pPime_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_SCALARSSTORE_H