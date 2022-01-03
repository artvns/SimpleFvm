#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_MOVINGWALLSOURCEPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_MOVINGWALLSOURCEPORT_H

#include "FVMSolver/BoundaryConditions/BcParametersStores/MovingWallBcParamsStore.h"

#include "AbstractSourcePort.h"


namespace fvmsolver {

class MovingWallSourcePort : public AbstractSourcePort {
public:
    MovingWallSourcePort(const SolverFluidPropsMask& fluid, 
                         const SolverMeshParamsMask& mesh,
                         const SolverAdjCellsTypeMask& adjCellsType, 
                         const SolverCellNumsGlobalMask& nums,
                         const MovingWallBcParamsStore& bcParamsStore);

    double getWallVelocity() const override; 

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_MOVINGWALLSOURCEPORT_H