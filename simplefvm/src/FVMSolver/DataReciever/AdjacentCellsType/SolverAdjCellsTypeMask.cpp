#include "SolverAdjCellsTypeMask.h"

namespace fvmsolver {

SolverAdjCellsTypeMask::SolverAdjCellsTypeMask(
                RecievedDataStore& store) : store_(store) {

}

EnumAdjacentCellTypes SolverAdjCellsTypeMask::getCellType(size_t index) const {

    if (datastores::ADJACENT_CELL_INTERIOR == 
                                    store_.getCellType().getValue(index)) {
        return ADJACENT_CELL_INTERIOR;
    }
    else if (datastores::ADJACENT_CELL_BC_REAL == 
                                    store_.getCellType().getValue(index)) {
        return ADJACENT_CELL_BC_REAL;
    }
    else {
        return ADJACENT_CELL_BC_GHOST;
    }
}

}