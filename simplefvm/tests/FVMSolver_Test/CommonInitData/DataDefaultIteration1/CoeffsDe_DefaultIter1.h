#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_COEFFSDEDEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_COEFFSDEDEFAULTITER1_H

#include <cstddef>

#include "FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h"


namespace commoninitdata {

using namespace fvmsolver;


class CoeffsDe_DefaultIter1 {
public:
    CoeffsDe_DefaultIter1();

    void createCoeffsCalculators();
    CoeffsCalculatorsStore& getCoeffsCalculatorsStore();

private:
    CoeffsCalculatorsStore coeffsCalculators_;

    size_t cells_u_ = 20;
    size_t cells_v_ = 20;

    void createDeU();
    void createDeV();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_COEFFSDEDEFAULTITER1_H