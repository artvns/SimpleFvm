#include "RhsVPort.h"

namespace fvmsolver {

RhsVPort::RhsVPort( const SolverFieldsMask& fields, 
                    const SolverMeshParamsMask& mesh, 
                    const SolverCellNumsGlobalMask& nums, 
                    const SolverAdjCellGlobalNumsVMask& adjCellNums) :
                                    fields_(fields),
                                    mesh_(mesh),
                                    nums_(nums),
                                    adjCellNums_(adjCellNums) {

}


double RhsVPort::get_alphaV() const {
    return alphaV_;
}

double RhsVPort::get_v(size_t num) const {
    return fields_.getV(num);
}

double RhsVPort::get_p(size_t num) const {
    return fields_.getP(num);
}

double RhsVPort::get_dX(size_t step) const {
    return mesh_.get_dX(step);
}

size_t RhsVPort::getNumVp(size_t step) const {
    return nums_.get_pCellNum(step);
}

size_t RhsVPort::getNumVs(size_t step) const {
    return adjCellNums_.getNumVs(step);
}

}