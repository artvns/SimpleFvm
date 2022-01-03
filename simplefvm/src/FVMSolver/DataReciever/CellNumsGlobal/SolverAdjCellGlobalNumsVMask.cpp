#include "SolverAdjCellGlobalNumsVMask.h"

namespace fvmsolver {

SolverAdjCellGlobalNumsVMask::SolverAdjCellGlobalNumsVMask(
                        RecievedDataStore& store) : store_(store) {

}

size_t SolverAdjCellGlobalNumsVMask::getNumVn(size_t index) const {
    return store_.getNumVn().getValue(index);
}

size_t SolverAdjCellGlobalNumsVMask::getNumVs(size_t index) const {
    return store_.getNumVs().getValue(index);
}

size_t SolverAdjCellGlobalNumsVMask::getNumUwn(size_t index) const {
    return store_.getNumUwn().getValue(index);
}

size_t SolverAdjCellGlobalNumsVMask::getNumUws(size_t index) const {
    return store_.getNumUws().getValue(index);
}

size_t SolverAdjCellGlobalNumsVMask::getNumUen(size_t index) const {
    return store_.getNumUen().getValue(index);
}

size_t SolverAdjCellGlobalNumsVMask::getNumUes(size_t index) const {
    return store_.getNumUes().getValue(index);
}
    
size_t SolverAdjCellGlobalNumsVMask::getNumPp(size_t index) const {
    return store_.getNumPp().getValue(index);
}

size_t SolverAdjCellGlobalNumsVMask::getNumPs(size_t index) const {
    return store_.getNumPs().getValue(index);
}

}