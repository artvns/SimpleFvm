#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSUPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSUPORT_H

#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsUMask.h"


namespace fvmsolver {

class RhsUPort {
public:
    RhsUPort(const SolverFieldsMask& fields, 
             const SolverMeshParamsMask& mesh, 
             const SolverCellNumsGlobalMask& nums, 
             const SolverAdjCellGlobalNumsUMask& adjCellNums);

    double get_alphaU() const;
    double get_u(size_t num) const;
    double get_p(size_t num) const;
    double get_dY(size_t step) const;
    size_t getNumUp(size_t step) const;
    size_t getNumUw(size_t step) const;

private:
    const SolverFieldsMask& fields_;
    const SolverMeshParamsMask& mesh_;
    const SolverCellNumsGlobalMask& nums_;
    const SolverAdjCellGlobalNumsUMask& adjCellNums_;

    const double alphaU_ = 0.7;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSUPORT_H