#include "SolverAdjCellInteriorNumsPMask.h"

namespace fvmsolver {

SolverAdjCellInteriorNumsPMask::SolverAdjCellInteriorNumsPMask(
                        RecievedDataStore& store) : store_(store) {

}

size_t SolverAdjCellInteriorNumsPMask::get_numUStarW(size_t index) const {
    return store_.get_numUStarW().getValue(index);
}

size_t SolverAdjCellInteriorNumsPMask::get_numUStarE(size_t index) const {
    return store_.get_numUStarE().getValue(index);
}

size_t SolverAdjCellInteriorNumsPMask::get_numVStarN(size_t index) const {
    return store_.get_numVStarN().getValue(index);
}

size_t SolverAdjCellInteriorNumsPMask::get_numVStarS(size_t index) const {
    return store_.get_numVStarS().getValue(index);
}

}