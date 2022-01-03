#include "SolverAdjCellInteriorNumsUMask.h"

namespace fvmsolver {

SolverAdjCellInteriorNumsUMask::SolverAdjCellInteriorNumsUMask(
                        RecievedDataStore& store) : store_(store) {

}

size_t SolverAdjCellInteriorNumsUMask::get_numPp(size_t index) const {
    return store_.get_numPp().getValue(index);
}

size_t SolverAdjCellInteriorNumsUMask::get_numPw(size_t index) const {
    return store_.get_numPw().getValue(index);
}

}