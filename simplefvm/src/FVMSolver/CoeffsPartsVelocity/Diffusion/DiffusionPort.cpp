#include "DiffusionPort.h"

namespace fvmsolver {

DiffusionPort::DiffusionPort(
                    const SolverFluidPropsMask& fluid,
                    const SolverMeshParamsMask& mesh,
                    const SolverCellNumsGlobalMask& nums) : 
                                fluid_(fluid), 
                                mesh_(mesh),
                                nums_(nums) {

}

double DiffusionPort::getMU() const {
    return fluid_.getMU();
}

size_t DiffusionPort::getNumCellp(size_t step) const {
    return nums_.get_pCellNum(step);
}

double DiffusionPort::get_dX(size_t num) const {
    return mesh_.get_dX(num);
}

double DiffusionPort::get_dY(size_t num) const {
    return mesh_.get_dY(num);
}

}