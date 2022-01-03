#ifndef SIMPLEFVM_FLUIDPROPSMODULE_H
#define SIMPLEFVM_FLUIDPROPSMODULE_H

#include <memory>

#include "MSolverMacros.h"


namespace mainsolver {

class SolverFluidPropsDefiner;

class SFVM_API_ FluidPropsModule {
public:
    FluidPropsModule();
    ~FluidPropsModule();
    
    void setDynamicViscosity(const double MU);
    void setDensity(const double RHO);

    SolverFluidPropsDefiner& getFluidPropsDefiner() const;

private:
    SolverFluidPropsDefiner* spObj_ = nullptr;
};

}
#endif // SIMPLEFVM_FLUIDPROPSMODULE_H