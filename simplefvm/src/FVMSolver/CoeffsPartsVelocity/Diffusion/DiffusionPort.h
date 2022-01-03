#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONPORT_H

#include <cstddef>

#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"


namespace fvmsolver {

class DiffusionPort {
public:
    DiffusionPort(  const SolverFluidPropsMask& fluid, 
                    const SolverMeshParamsMask& mesh,
                    const SolverCellNumsGlobalMask& nums);

    double getMU() const;
    size_t getNumCellp(size_t step) const;
    double get_dX(size_t num) const;
    double get_dY(size_t num) const;

private:
    const SolverFluidPropsMask& fluid_;
    const SolverMeshParamsMask& mesh_;
    const SolverCellNumsGlobalMask& nums_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONPORT_H