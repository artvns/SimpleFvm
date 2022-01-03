#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_UFLUX_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_UFLUX_H

#include "AbstractFlux.h"


namespace fvmsolver {

class UFlux : public AbstractFlux {
private:
    using uPtrDataPort = std::unique_ptr<UFluxPort>;

public:
    UFlux(uPtrDataPort spData);

    void calculate(size_t step) override;
    
private:
    uPtrDataPort spData_ = nullptr;
    const UFluxPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_UFLUX_H