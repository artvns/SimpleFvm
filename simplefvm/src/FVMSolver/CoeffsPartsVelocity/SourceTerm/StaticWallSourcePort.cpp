#include "StaticWallSourcePort.h"

namespace fvmsolver {

StaticWallSourcePort::StaticWallSourcePort(
        const SolverFluidPropsMask& fluid, 
        const SolverMeshParamsMask& mesh,
        const SolverAdjCellsTypeMask& adjCellsType, 
        const SolverCellNumsGlobalMask& nums) : 
                        AbstractSourcePort( fluid, 
                                            mesh, 
                                            adjCellsType,
                                            nums) {

}

}