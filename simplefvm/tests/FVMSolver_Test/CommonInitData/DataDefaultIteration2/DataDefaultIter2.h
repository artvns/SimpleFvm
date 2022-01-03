#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_DATADEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_DATADEFAULTITER2_H

#include "CoeffsDe_DefaultIter2.h"
#include "CalcedScalars_DefaultIter2.h"
#include "Fields_DefaultIter2.h"
#include "FluidProps_DefaultIter2.h"
#include "MeshParams_DefaultIter2.h"


namespace commoninitdata {

class DataDefaultIter2 {
public:
    DataDefaultIter2();

    void initializeFluid();
    void initializeCoeffs_de();
    void initializeFields();
    void initializeMeshData();
    void initializeCalculatedScalars();

    FluidProps_DefaultIter2& getFluidProps();
    MeshParams_DefaultIter2& getMeshParams();
    Fields_DefaultIter2& getFieldsIterations();
    CoeffsDe_DefaultIter2& getCoeffsDeIterations();
    CalcedScalars_DefaultIter2& getCalcScalarsIterations();

private:
    FluidProps_DefaultIter2 fluidProps_;
    MeshParams_DefaultIter2 meshParams_;
    Fields_DefaultIter2 fieldsIterations_;
    CoeffsDe_DefaultIter2 coeffsDeIterations_;
    CalcedScalars_DefaultIter2 calcScalarsIterations_;
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION2_DATADEFAULTITER2_H