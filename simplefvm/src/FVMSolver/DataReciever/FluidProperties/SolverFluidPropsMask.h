#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_FLUIDPROPERTIES_SOLVERFLUIDPROPSMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_FLUIDPROPERTIES_SOLVERFLUIDPROPSMASK_H

#include "DataStores/FluidPropertiesStores/FluidPropertiesStore.h"


namespace fvmsolver {

class SolverFluidPropsMask {
private:
    using RecievedDataStore = datastores::FluidPropertiesStore;

public:
    SolverFluidPropsMask(RecievedDataStore& store);

    double getRHO() const;
    double getMU() const;

    void setRHO(double RHO);
    void setMU(double MU);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_FLUIDPROPERTIES_SOLVERFLUIDPROPSMASK_H