#include "SolverMeshParamsMask.h"

namespace fvmsolver {

SolverMeshParamsMask::SolverMeshParamsMask(
        RecievedDataStore& store) : store_(store) {

}

double SolverMeshParamsMask::get_dX(size_t index) const {
    return store_.get_dX().getValue(index);
}

double SolverMeshParamsMask::get_dY(size_t index) const {
    return store_.get_dY().getValue(index);
}

}