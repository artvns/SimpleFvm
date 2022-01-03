#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPES_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPES_H

#include <cstddef>
#include <memory>

#include "FVMSolver/Tools/Enums/EnumAdjacentCellTypes.cpp"

#include "CellTypesPort.h"


namespace fvmsolver {

class CellTypes {
private:
    using uPtrDataPort = std::unique_ptr<CellTypesPort>;

public:
    CellTypes(uPtrDataPort spData);

    void assignCurrentCellValues(size_t step);
    EnumAdjacentCellTypes get_wType();
    EnumAdjacentCellTypes get_eType();
    EnumAdjacentCellTypes get_nType();
    EnumAdjacentCellTypes get_sType();
    
private:
    uPtrDataPort spData_ = nullptr;
    const CellTypesPort& data_;
    
    EnumAdjacentCellTypes wType_;
    EnumAdjacentCellTypes eType_;
    EnumAdjacentCellTypes nType_;
    EnumAdjacentCellTypes sType_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPES_H