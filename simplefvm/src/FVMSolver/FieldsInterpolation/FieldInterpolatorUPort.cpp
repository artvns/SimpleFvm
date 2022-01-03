#include "FieldInterpolatorUPort.h"

namespace fvmsolver {

FieldInterpolatorUPort::FieldInterpolatorUPort(
                SolverFieldsMask& fields,
                const SolverMeshParamsMask& mesh,
                const SolverCellNumsGlobalMask& numsGlob, 
                const SolverAdjCellGlobalNumsPMask& adjNumsGlobal) : 
                                fields_(fields),
                                mesh_(mesh),
                                numsGlob_(numsGlob),
                                adjNumsGlobal_(adjNumsGlobal) {

}

double FieldInterpolatorUPort::getU(const size_t num) const {
    return fields_.getU(num);
}

double FieldInterpolatorUPort::get_dX(const size_t num) const {
    return mesh_.get_dX(num);
}

size_t FieldInterpolatorUPort::getNumPp(const size_t step) const {
    return numsGlob_.get_pCellNum(step);
}

size_t FieldInterpolatorUPort::getNumUw(const size_t step) const {
    return adjNumsGlobal_.get_numUStarW(step);
}

size_t FieldInterpolatorUPort::getNumUe(const size_t step) const {
    return adjNumsGlobal_.get_numUStarE(step);
}

void FieldInterpolatorUPort::setCellCenteredU(const size_t num, double value) {
    fields_.set_uCellCentered(num, value);
}

}