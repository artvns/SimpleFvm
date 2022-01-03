#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESPORT_H

#include "FVMSolver/Tools/Enums/EnumAdjacentCellTypes.cpp"
#include "FVMSolver/DataReciever/AdjacentCellsType/SolverAdjCellsTypeMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"


namespace fvmsolver {

class CellTypesPort {
public:
    CellTypesPort(const SolverAdjCellsTypeMask& types, 
                    const SolverCellNumsGlobalMask& nums);

    EnumAdjacentCellTypes getType(size_t pos) const;
    size_t get_pNum(size_t step) const;
    size_t get_wNum(size_t step) const;
    size_t get_eNum(size_t step) const;
    size_t get_nNum(size_t step) const;
    size_t get_sNum(size_t step) const;

private:
    const SolverAdjCellsTypeMask& types_;
    const SolverCellNumsGlobalMask& nums_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESPORT_H