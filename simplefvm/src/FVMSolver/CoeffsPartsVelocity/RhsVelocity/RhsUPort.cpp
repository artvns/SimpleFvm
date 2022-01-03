#include "RhsUPort.h"

namespace fvmsolver {

RhsUPort::RhsUPort( const SolverFieldsMask& fields, 
                    const SolverMeshParamsMask& mesh, 
                    const SolverCellNumsGlobalMask& nums, 
                    const SolverAdjCellGlobalNumsUMask& adjCellNums) :
                                    fields_(fields),
                                    mesh_(mesh),
                                    nums_(nums),
                                    adjCellNums_(adjCellNums) {

}


double RhsUPort::get_alphaU() const {
    return alphaU_;
}

double RhsUPort::get_u(size_t num) const {
    return fields_.getU(num);
}

double RhsUPort::get_p(size_t num) const {
    return fields_.getP(num);
}

double RhsUPort::get_dY(size_t step) const {
    return mesh_.get_dY(step);
}

size_t RhsUPort::getNumUp(size_t step) const {
    return nums_.get_pCellNum(step);
}

size_t RhsUPort::getNumUw(size_t step) const {
    return adjCellNums_.getNumUw(step);
}

}