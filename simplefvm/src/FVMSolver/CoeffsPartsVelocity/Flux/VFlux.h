#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_VFLUX_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_VFLUX_H

#include "AbstractFlux.h"


namespace fvmsolver {

class VFlux : public AbstractFlux {
private:
    using uPtrDataPort = std::unique_ptr<VFluxPort>;

public:
    VFlux(uPtrDataPort spData);

    void calculate(size_t step) override;
    
private:
    uPtrDataPort spData_ = nullptr;
    const VFluxPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_VFLUX_H