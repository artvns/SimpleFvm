#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_FIELDSDEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_FIELDSDEFAULTITER2_H

#include <cstddef>

#include "DataStores/FieldsStores/FieldsStore.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"


namespace commoninitdata {

using namespace datastores;


class Fields_DefaultIter2 {
public:
    Fields_DefaultIter2();

    void createFields();
    fvmsolver::SolverFieldsMask& getFieldsMask();

private:
    FieldsStore fields_;

    fvmsolver::SolverFieldsMask fieldsMask_;

    size_t cells_u_ = 45;
    size_t cells_v_ = 45;
    size_t cells_p_ = 45;

    void createU();
    void createV();
    void createP();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_FIELDSDEFAULTITER2_H