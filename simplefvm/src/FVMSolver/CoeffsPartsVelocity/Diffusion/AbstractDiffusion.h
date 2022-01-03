#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_ABSTRACTDIFFUSION_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_ABSTRACTDIFFUSION_H

#include <cstddef>
#include <memory>

#include "DiffusionPort.h"


namespace fvmsolver {

class AbstractDiffusion {
protected:
    using uPtrDataPort = std::unique_ptr<DiffusionPort>;

public:
    AbstractDiffusion(uPtrDataPort spData);
    virtual ~AbstractDiffusion() = 0;

    virtual void calculate(size_t step) = 0;

    double getDw();
    double getDe();
    double getDn();
    double getDs();

protected:
    uPtrDataPort spData_ = nullptr;
    const DiffusionPort& data_;

    double Dw_ = 0.0;
    double De_ = 0.0;
    double Dn_ = 0.0;
    double Ds_ = 0.0;

    double MU_ = 0.0;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_ABSTRACTDIFFUSION_H