#include "FluidPropsValidatior.h"

namespace fvmsolver {


FluidPropsValidatior::FluidPropsValidatior(
        SolverSingleMasks& singleMasks) : 
                MU_(singleMasks.getFluidPropertiesMask().getMU()),
                RHO_(singleMasks.getFluidPropertiesMask().getRHO()) {

}


void FluidPropsValidatior::validateData() const {
    validateViscosity();
    validateDensity();
}


void FluidPropsValidatior::validateViscosity() const {
    if (MU_ <= 0) {
        throw customexceptions::FluidPropertiesEcxeption(
                    "Unacceptable value of viscosity (MU)...", MU_);
    }
}


void FluidPropsValidatior::validateDensity() const {
    if (RHO_ <= 0) {
        throw customexceptions::FluidPropertiesEcxeption(
                    "Unacceptable value of density (RHO)...", RHO_);
    }
}

}