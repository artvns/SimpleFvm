#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_FLUIDPROPSDEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_FLUIDPROPSDEFAULTITER1_H

#include "DataStores/FluidPropertiesStores/FluidPropertiesStore.h"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"


namespace commoninitdata {

using namespace datastores;


class FluidProps_DefaultIter1 {
public:
    FluidProps_DefaultIter1();

    void initializeProps();
    fvmsolver::SolverFluidPropsMask& getFluidPropertiesStore();

private:
    datastores::FluidPropertiesStore fluidProps_;
    fvmsolver::SolverFluidPropsMask fluidPropsMask_;
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_FLUIDPROPSDEFAULTITER1_H