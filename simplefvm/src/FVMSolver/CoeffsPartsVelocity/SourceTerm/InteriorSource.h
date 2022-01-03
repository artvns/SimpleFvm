#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_INTERIORSOURCE_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_INTERIORSOURCE_H

#include "AbstractSource.h"


namespace fvmsolver {

class InteriorSource : public AbstractSource {
public:
    InteriorSource();

    void calculate(size_t step) override;
    
private:
    void calculateForUMesh();
    void calculateForVMesh();
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_INTERIORSOURCE_H