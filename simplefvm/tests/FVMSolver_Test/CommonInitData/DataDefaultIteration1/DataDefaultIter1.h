#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_DATADEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_DATADEFAULTITER1_H

#include "CoeffsDe_DefaultIter1.h"
#include "CalcedScalars_DefaultIter1.h"
#include "Fields_DefaultIter1.h"
#include "FluidProps_DefaultIter1.h"
#include "MeshParams_DefaultIter1.h"


namespace commoninitdata {

class DataDefaultIter1 {
public:
    DataDefaultIter1();

    void initializeFluid();
    void initializeCoeffs_de();
    void initializeFields();
    void initializeMeshData();
    void initializeCalculatedScalars();

    FluidProps_DefaultIter1& getFluidProps();
    MeshParams_DefaultIter1& getMeshParams();
    Fields_DefaultIter1& getFieldsIterations();
    CoeffsDe_DefaultIter1& getCoeffsDeIterations();
    CalcedScalars_DefaultIter1& getCalcScalarsIterations();

private:
    FluidProps_DefaultIter1 fluidProps_;
    MeshParams_DefaultIter1 meshParams_;
    Fields_DefaultIter1 fieldsIterations_;
    CoeffsDe_DefaultIter1 coeffsDeIterations_;
    CalcedScalars_DefaultIter1 calcScalarsIterations_;
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_DATADEFAULTITER1_H