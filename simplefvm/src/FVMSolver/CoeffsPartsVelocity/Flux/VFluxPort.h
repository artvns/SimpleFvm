#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_VFLUXPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_VFLUXPORT_H

#include <cstddef>

#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsVMask.h"


namespace fvmsolver {

class VFluxPort {
public:
    VFluxPort(const SolverFluidPropsMask& fluid, 
              const SolverFieldsMask& fields, 
              const SolverMeshParamsMask& mesh, 
              const SolverCellNumsGlobalMask& nums,
              const SolverAdjCellGlobalNumsVMask& adjCellNums);

    double getRHO() const;

    double get_u(size_t num) const;
    double get_v(size_t num) const;

    double get_dX(size_t step) const;
    double get_dY(size_t step) const;

    size_t getNumVp(size_t step) const;
    size_t getNumVn(size_t step) const;
    size_t getNumVs(size_t step) const;

    size_t getNumUwn(size_t step) const;
    size_t getNumUws(size_t step) const;
    size_t getNumUen(size_t step) const;
    size_t getNumUes(size_t step) const;

private:
    const SolverFluidPropsMask& fluid_;
    const SolverFieldsMask& fields_;
    const SolverMeshParamsMask& mesh_;
    const SolverCellNumsGlobalMask& nums_;
    const SolverAdjCellGlobalNumsVMask& adjCellNums_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_VFLUXPORT_H