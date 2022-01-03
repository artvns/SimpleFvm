#include "FluidProps_DefaultIter2.h"

namespace commoninitdata {

FluidProps_DefaultIter2::FluidProps_DefaultIter2() : 
            fluidPropsMask_(fluidProps_) {

}

fvmsolver::SolverFluidPropsMask& FluidProps_DefaultIter2::getFluidPropertiesStore() {
    return fluidPropsMask_;
}

void FluidProps_DefaultIter2::initializeProps() {
    fluidProps_.setRHO(998.0);
    fluidProps_.setMU(0.001004);
}

}