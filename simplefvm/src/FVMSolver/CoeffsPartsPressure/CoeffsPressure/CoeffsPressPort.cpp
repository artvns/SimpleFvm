#include "CoeffsPressPort.h"

namespace fvmsolver {

CoeffsPressPort::CoeffsPressPort(
                const SolverFluidPropsMask& fluid, 
                const SolverMeshParamsMask& mesh,
                const SolverCellNumsGlobalMask& numsGlob, 
                const SolverAdjCellInteriorNumsPMask& adjNumsInterior,
                CoeffsCalculatorsStore& coeffsCalculators) : 
                                fluid_(fluid), 
                                mesh_(mesh),
                                numsGlob_(numsGlob),
                                adjNumsInterior_(adjNumsInterior),
                                coeffsCalculators_(coeffsCalculators) {

}


double CoeffsPressPort::getRHO() const {
    return fluid_.getRHO();
}

double CoeffsPressPort::get_dX(size_t num) const {
    return mesh_.get_dX(num);
}

double CoeffsPressPort::get_dY(size_t num) const {
    return mesh_.get_dY(num);
}

size_t CoeffsPressPort::getNumPp(size_t step) const {
    return numsGlob_.get_pCellNum(step);
}

size_t CoeffsPressPort::getNumUStarW(size_t step) const {
    return adjNumsInterior_.get_numUStarW(step);
}

size_t CoeffsPressPort::getNumUStarE(size_t step) const {
    return adjNumsInterior_.get_numUStarE(step);
}

size_t CoeffsPressPort::getNumVStarN(size_t step) const {
    return adjNumsInterior_.get_numVStarN(step);
}

size_t CoeffsPressPort::getNumVStarS(size_t step) const {
    return adjNumsInterior_.get_numVStarS(step);
}

double CoeffsPressPort::get_deU(size_t num) const {
    return coeffsCalculators_.get_deU(num);
}

double CoeffsPressPort::get_deV(size_t num) const {
    return coeffsCalculators_.get_deV(num);
}

}