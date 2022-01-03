#include "SolverAdjCellInteriorNumsVMask.h"

namespace fvmsolver {

SolverAdjCellInteriorNumsVMask::SolverAdjCellInteriorNumsVMask(
                        RecievedDataStore& store) : store_(store) {

}

size_t SolverAdjCellInteriorNumsVMask::get_numPp(size_t index) const {
    return store_.get_numPp().getValue(index);
}

size_t SolverAdjCellInteriorNumsVMask::get_numPs(size_t index) const {
    return store_.get_numPs().getValue(index);
}

}