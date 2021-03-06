#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_UDIFFUSION_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_UDIFFUSION_H

#include <iostream>

#include "AbstractDiffusion.h"


namespace fvmsolver {

class UDiffusion : public AbstractDiffusion {
public:
    UDiffusion(uPtrDataPort spData);

    void calculate(size_t step) override;
    
private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_UDIFFUSION_H