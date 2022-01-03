#include "FieldInterpolatorVPort.h"

namespace fvmsolver {

FieldInterpolatorVPort::FieldInterpolatorVPort(
                SolverFieldsMask& fields,
                const SolverMeshParamsMask& mesh,
                const SolverCellNumsGlobalMask& numsGlob, 
                const SolverAdjCellGlobalNumsPMask& adjNumsGlobal) : 
                                fields_(fields),
                                mesh_(mesh),
                                numsGlob_(numsGlob),
                                adjNumsGlobal_(adjNumsGlobal) {

}

double FieldInterpolatorVPort::getV(const size_t num) const {
    return fields_.getV(num);
}

double FieldInterpolatorVPort::get_dY(const size_t num) const {
    return mesh_.get_dY(num);
}

size_t FieldInterpolatorVPort::getNumPp(const size_t step) const {
    return numsGlob_.get_pCellNum(step);
}

size_t FieldInterpolatorVPort::getNumVn(const size_t step) const {
    return adjNumsGlobal_.get_numVStarN(step);
}

size_t FieldInterpolatorVPort::getNumVs(const size_t step) const {
    return adjNumsGlobal_.get_numVStarS(step);
}

void FieldInterpolatorVPort::setCellCenteredV(const size_t num, double value) {
    fields_.set_vCellCentered(num, value);
}

}