#include "FluidProps_DefaultIter1.h"

namespace commoninitdata {

FluidProps_DefaultIter1::FluidProps_DefaultIter1() : 
            fluidPropsMask_(fluidProps_) {

}

fvmsolver::SolverFluidPropsMask& FluidProps_DefaultIter1::getFluidPropertiesStore() {
    return fluidPropsMask_;
}

void FluidProps_DefaultIter1::initializeProps() {
    fluidProps_.setRHO(998.0);
    fluidProps_.setMU(0.001004);
}

}