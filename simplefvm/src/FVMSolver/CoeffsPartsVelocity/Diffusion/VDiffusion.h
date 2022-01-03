#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_VDIFFUSION_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_VDIFFUSION_H

#include <iostream>

#include "AbstractDiffusion.h"


namespace fvmsolver {

class VDiffusion : public AbstractDiffusion {
public:
    VDiffusion(uPtrDataPort spData);

    void calculate(size_t step) override;
    
private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_VDIFFUSION_H