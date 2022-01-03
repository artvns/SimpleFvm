#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVPORT_H

#include <cstddef>

#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsVMask.h"


namespace fvmsolver {

class RhsVPort {
public:
    RhsVPort(const SolverFieldsMask& fields, 
             const SolverMeshParamsMask& mesh, 
             const SolverCellNumsGlobalMask& nums, 
             const SolverAdjCellGlobalNumsVMask& adjCellNums);

    double get_alphaV() const;
    double get_v(size_t num) const;
    double get_p(size_t num) const;
    double get_dX(size_t step) const;
    size_t getNumVp(size_t step) const;
    size_t getNumVs(size_t step) const;

private:
    const SolverFieldsMask& fields_;
    const SolverMeshParamsMask& mesh_;
    const SolverCellNumsGlobalMask& nums_;
    const SolverAdjCellGlobalNumsVMask& adjCellNums_;

    const double alphaV_ = 0.7;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVPORT_H