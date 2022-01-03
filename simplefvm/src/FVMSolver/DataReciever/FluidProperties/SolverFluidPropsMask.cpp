#include "SolverFluidPropsMask.h"

namespace fvmsolver {

SolverFluidPropsMask::SolverFluidPropsMask(
        RecievedDataStore& store) : store_(store) {

}

double SolverFluidPropsMask::getRHO() const {
    return store_.getRHO();
}

double SolverFluidPropsMask::getMU() const {
    return store_.getMU();
}


void SolverFluidPropsMask::setRHO(double RHO) {
    store_.setRHO(RHO);
}

void SolverFluidPropsMask::setMU(double MU) {
    store_.setMU(MU);
}

}