#include "MovingWallSourcePort.h"

namespace fvmsolver {

MovingWallSourcePort::MovingWallSourcePort(
        const SolverFluidPropsMask& fluid, 
        const SolverMeshParamsMask& mesh,
        const SolverAdjCellsTypeMask& adjCellsType, 
        const SolverCellNumsGlobalMask& nums,
        const MovingWallBcParamsStore& bcParamsStore) :   
                        AbstractSourcePort( fluid, 
                                            mesh, 
                                            adjCellsType,
                                            nums) {
                                              
    wallVelocity_ = bcParamsStore.getWallVelocity();
}

double MovingWallSourcePort::getWallVelocity() const {
        return wallVelocity_;
}

}