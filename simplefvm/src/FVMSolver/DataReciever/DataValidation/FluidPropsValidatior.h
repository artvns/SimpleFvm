#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_DATAVALIDATION_FLUIDPROPSVALIDATIOR_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_DATAVALIDATION_FLUIDPROPSVALIDATIOR_H

#include "CustomExceptions/FluidPropertiesEcxeption.h"

#include "../SolverSingleMasks.h"


namespace fvmsolver {

class FluidPropsValidatior {
public:
    FluidPropsValidatior(SolverSingleMasks& singleMasks);

    void validateData() const;

private:
    double MU_ = 0.0;
    double RHO_ = 0.0;

    void validateViscosity() const;
    void validateDensity() const;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_DATAVALIDATION_FLUIDPROPSVALIDATIOR_H