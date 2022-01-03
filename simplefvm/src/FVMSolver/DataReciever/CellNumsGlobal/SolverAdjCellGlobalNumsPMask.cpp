#include "SolverAdjCellGlobalNumsPMask.h"

namespace fvmsolver {

SolverAdjCellGlobalNumsPMask::SolverAdjCellGlobalNumsPMask(
                    RecievedDataStore& store) : store_(store) {

}

size_t SolverAdjCellGlobalNumsPMask::get_numUStarW(size_t index) const {
    return store_.get_numUStarW().getValue(index);
}

size_t SolverAdjCellGlobalNumsPMask::get_numUStarE(size_t index) const {
    return store_.get_numUStarE().getValue(index);
}

size_t SolverAdjCellGlobalNumsPMask::get_numVStarN(size_t index) const {
    return store_.get_numVStarN().getValue(index);
}

size_t SolverAdjCellGlobalNumsPMask::get_numVStarS(size_t index) const {
    return store_.get_numVStarS().getValue(index);
}

}