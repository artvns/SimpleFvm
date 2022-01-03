#include "RhsPressPort.h"

namespace fvmsolver {

RhsPressPort::RhsPressPort(
                const SolverFluidPropsMask& fluid, 
                const SolverMeshParamsMask& mesh,
                const SolverCellNumsGlobalMask& numsGlob, 
                const SolverAdjCellInteriorNumsPMask& adjNumsInterior,
                ScalarsStore& scalarsStore) : 
                                fluid_(fluid), 
                                mesh_(mesh),
                                numsGlob_(numsGlob),
                                adjNumsInterior_(adjNumsInterior),
                                scalarsStore_(scalarsStore) {

}


double RhsPressPort::getRHO() const {
    return fluid_.getRHO();
}

double RhsPressPort::get_dX(size_t num) const {
    return mesh_.get_dX(num);
}

double RhsPressPort::get_dY(size_t num) const {
    return mesh_.get_dY(num);
}

size_t RhsPressPort::getNumPp(size_t step) const {
    return numsGlob_.get_pCellNum(step);
}

size_t RhsPressPort::getNumUStarW(size_t step) const {
    return adjNumsInterior_.get_numUStarW(step);
}

size_t RhsPressPort::getNumUStarE(size_t step) const {
    return adjNumsInterior_.get_numUStarE(step);
}

size_t RhsPressPort::getNumVStarN(size_t step) const {
    return adjNumsInterior_.get_numVStarN(step);
}

size_t RhsPressPort::getNumVStarS(size_t step) const {
    return adjNumsInterior_.get_numVStarS(step);
}


CalculatedScalar& RhsPressPort::getUStar() const {
    return scalarsStore_.get_uStar();
}
CalculatedScalar& RhsPressPort::getVStar() const {
    return scalarsStore_.get_vStar();
}

}