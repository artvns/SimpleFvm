#include "SolverAdjCellGlobalNumsUMask.h"

namespace fvmsolver {

SolverAdjCellGlobalNumsUMask::SolverAdjCellGlobalNumsUMask(
                        RecievedDataStore& store) : store_(store) {
}

size_t SolverAdjCellGlobalNumsUMask::getNumUw(size_t index) const {
    return store_.getNumUw().getValue(index);
}

size_t SolverAdjCellGlobalNumsUMask::getNumUe(size_t index) const {
    return store_.getNumUe().getValue(index);
}

size_t SolverAdjCellGlobalNumsUMask::getNumVnw(size_t index) const {
    return store_.getNumVnw().getValue(index);
}

size_t SolverAdjCellGlobalNumsUMask::getNumVne(size_t index) const {
    return store_.getNumVne().getValue(index);
}

size_t SolverAdjCellGlobalNumsUMask::getNumVsw(size_t index) const {
    return store_.getNumVsw().getValue(index);
}

size_t SolverAdjCellGlobalNumsUMask::getNumVse(size_t index) const {
    return store_.getNumVse().getValue(index);
}

size_t SolverAdjCellGlobalNumsUMask::getNumPp(size_t index) const {
    return store_.getNumVne().getValue(index);
}

size_t SolverAdjCellGlobalNumsUMask::getNumPw(size_t index) const {
    return store_.getNumPw().getValue(index);
}

}