#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_ABSTRACTFLUX_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_ABSTRACTFLUX_H

#include <cstddef>
#include <memory>

#include "UFluxPort.h"
#include "VFluxPort.h"


namespace fvmsolver {

class AbstractFlux {
public:
    AbstractFlux();
    virtual ~AbstractFlux() = 0;

    virtual void calculate(size_t step) = 0;

    double getFw();
    double getFe();
    double getFn();
    double getFs();

protected:
    double Fw_ = 0.0;
    double Fe_ = 0.0;
    double Fn_ = 0.0;
    double Fs_ = 0.0;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_ABSTRACTFLUX_H