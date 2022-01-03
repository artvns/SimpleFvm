#ifndef SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORUPORT_H
#define SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORUPORT_H

#include <cstddef>

#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsPMask.h"


namespace fvmsolver {

class FieldInterpolatorUPort {
public:
    FieldInterpolatorUPort( SolverFieldsMask& fields,
                            const SolverMeshParamsMask& mesh,
                            const SolverCellNumsGlobalMask& numsGlob, 
                            const SolverAdjCellGlobalNumsPMask& adjNumsGlobal);

    double getU(const size_t num) const;
    double get_dX(const size_t num) const;

    size_t getNumPp(const size_t step) const;
    size_t getNumUw(const size_t step) const;
    size_t getNumUe(const size_t step) const;

    void setCellCenteredU(const size_t num, double value);

private:
    SolverFieldsMask& fields_;    
    const SolverMeshParamsMask& mesh_;
    const SolverCellNumsGlobalMask& numsGlob_;
    const SolverAdjCellGlobalNumsPMask& adjNumsGlobal_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORUPORT_H