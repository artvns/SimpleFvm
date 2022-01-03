#include "UFluxPort.h"

namespace fvmsolver {

UFluxPort::UFluxPort(
            const SolverFluidPropsMask& fluid, 
            const SolverFieldsMask& fields, 
            const SolverMeshParamsMask& mesh, 
            const SolverCellNumsGlobalMask& nums,
            const SolverAdjCellGlobalNumsUMask& adjCellNums) :
                                    fluid_(fluid),
                                    fields_(fields),
                                    mesh_(mesh),
                                    nums_(nums),
                                    adjCellNums_(adjCellNums) {

}


double UFluxPort::getRHO() const {
    return fluid_.getRHO();
}

double UFluxPort::get_u(size_t num) const {
    return fields_.getU(num);
}

double UFluxPort::get_v(size_t num) const {
    return fields_.getV(num);
}

double UFluxPort::get_dX(size_t num) const {
    return mesh_.get_dX(num);
}

double UFluxPort::get_dY(size_t num) const {
    return mesh_.get_dY(num);
}

size_t UFluxPort::getNumUp(size_t step) const {
    return nums_.get_pCellNum(step);
}

size_t UFluxPort::getNumUw(size_t step) const {
    return adjCellNums_.getNumUw(step);
}

size_t UFluxPort::getNumUe(size_t step) const {
    return adjCellNums_.getNumUe(step);
}

size_t UFluxPort::getNumVnw(size_t step) const {
    return adjCellNums_.getNumVnw(step);
}

size_t UFluxPort::getNumVne(size_t step) const {
    return adjCellNums_.getNumVne(step);
}

size_t UFluxPort::getNumVsw(size_t step) const {
    return adjCellNums_.getNumVsw(step);
}

size_t UFluxPort::getNumVse(size_t step) const {
    return adjCellNums_.getNumVse(step);
}

}