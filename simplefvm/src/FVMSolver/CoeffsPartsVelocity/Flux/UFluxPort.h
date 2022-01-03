#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_UFLUXPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_UFLUXPORT_H

#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsUMask.h"


namespace fvmsolver {

class UFluxPort {
public:
    UFluxPort(const SolverFluidPropsMask& fluid, 
              const SolverFieldsMask& fields, 
              const SolverMeshParamsMask& mesh, 
              const SolverCellNumsGlobalMask& nums,
              const SolverAdjCellGlobalNumsUMask& adjCellNums);

    double getRHO() const;

    double get_u(size_t num) const;
    double get_v(size_t num) const;

    double get_dX(size_t num) const;
    double get_dY(size_t num) const;

    size_t getNumUp(size_t step) const;
    size_t getNumUw(size_t step) const;
    size_t getNumUe(size_t step) const;

    size_t getNumVnw(size_t step) const;
    size_t getNumVne(size_t step) const;
    size_t getNumVsw(size_t step) const;
    size_t getNumVse(size_t step) const;

private:
    const SolverFluidPropsMask& fluid_; 
    const SolverFieldsMask& fields_;
    const SolverMeshParamsMask& mesh_;
    const SolverCellNumsGlobalMask& nums_;
    const SolverAdjCellGlobalNumsUMask& adjCellNums_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_UFLUXPORT_H