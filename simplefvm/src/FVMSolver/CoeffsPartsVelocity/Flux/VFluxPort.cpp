#include "VFluxPort.h"

namespace fvmsolver {

VFluxPort::VFluxPort(
        const SolverFluidPropsMask& fluid, 
        const SolverFieldsMask& fields, 
        const SolverMeshParamsMask& mesh, 
        const SolverCellNumsGlobalMask& nums,
        const SolverAdjCellGlobalNumsVMask& adjCellNums) :
                                    fluid_(fluid),
                                    fields_(fields),
                                    mesh_(mesh),
                                    nums_(nums),
                                    adjCellNums_(adjCellNums) {

}


double VFluxPort::getRHO() const {
    return fluid_.getRHO();
}

double VFluxPort::get_u(size_t num) const {
    return fields_.getU(num);
}

double VFluxPort::get_v(size_t num) const {
    return fields_.getV(num);
}

double VFluxPort::get_dX(size_t step) const {
    return mesh_.get_dX(step);
}

double VFluxPort::get_dY(size_t step) const {
    return mesh_.get_dY(step);
}

size_t VFluxPort::getNumVp(size_t step) const {
    return nums_.get_pCellNum(step);
}

size_t VFluxPort::getNumVn(size_t step) const {
    return adjCellNums_.getNumVn(step);
}

size_t VFluxPort::getNumVs(size_t step) const {
    return adjCellNums_.getNumVs(step);
}

size_t VFluxPort::getNumUwn(size_t step) const {
    return adjCellNums_.getNumUwn(step);
}

size_t VFluxPort::getNumUws(size_t step) const {
    return adjCellNums_.getNumUws(step);
}

size_t VFluxPort::getNumUen(size_t step) const {
    return adjCellNums_.getNumUen(step);
}

size_t VFluxPort::getNumUes(size_t step) const {
    return adjCellNums_.getNumUes(step);
}

}