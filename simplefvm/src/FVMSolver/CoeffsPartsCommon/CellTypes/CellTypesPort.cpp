#include "CellTypesPort.h"

namespace fvmsolver {

CellTypesPort::CellTypesPort(
            const SolverAdjCellsTypeMask& types, 
            const SolverCellNumsGlobalMask& nums) :
                                    types_(types),
                                    nums_(nums) {

}


EnumAdjacentCellTypes CellTypesPort::getType(size_t pos) const {
    return types_.getCellType(pos);
}

size_t CellTypesPort::get_pNum(size_t step) const {
    return nums_.get_pCellNum(step);
}

size_t CellTypesPort::get_wNum(size_t step) const {
    return nums_.get_wCellNum(step); 
}

size_t CellTypesPort::get_eNum(size_t step) const {
    return nums_.get_eCellNum(step);
}

size_t CellTypesPort::get_nNum(size_t step) const {
    return nums_.get_nCellNum(step);
}

size_t CellTypesPort::get_sNum(size_t step) const {
    return nums_.get_sCellNum(step);
}

}