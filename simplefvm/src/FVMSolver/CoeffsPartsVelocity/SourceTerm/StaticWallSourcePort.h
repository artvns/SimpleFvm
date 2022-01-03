#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_STATICWALLSOURCEPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_STATICWALLSOURCEPORT_H

#include "AbstractSourcePort.h"


namespace fvmsolver {

class StaticWallSourcePort : public AbstractSourcePort {
public:
    StaticWallSourcePort(const SolverFluidPropsMask& fluid, 
                         const SolverMeshParamsMask& mesh,
                         const SolverAdjCellsTypeMask& adjCellsType, 
                         const SolverCellNumsGlobalMask& nums);

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_STATICWALLSOURCEPORT_H