#include "FluidPropsModule.h"

#include "SolverFluidPropsDefiner.h"

namespace mainsolver {

FluidPropsModule::FluidPropsModule() : 
                spObj_(new SolverFluidPropsDefiner()) {

}

FluidPropsModule::~FluidPropsModule() {
    delete spObj_;
    spObj_ = nullptr;
}

void FluidPropsModule::setDynamicViscosity(const double MU) {
    spObj_->setDynamicViscosity(MU);
}

void FluidPropsModule::setDensity(const double RHO) {
    spObj_->setDensity(RHO);
}

SolverFluidPropsDefiner& FluidPropsModule::getFluidPropsDefiner() const {
    return  *spObj_;
}

}