#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_COEFFSDEDEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_COEFFSDEDEFAULTITER2_H

#include <cstddef>

#include <FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h>


namespace commoninitdata {

using namespace fvmsolver;


class CoeffsDe_DefaultIter2 {
public:
    CoeffsDe_DefaultIter2();

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

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_COEFFSDEDEFAULTITER2_H