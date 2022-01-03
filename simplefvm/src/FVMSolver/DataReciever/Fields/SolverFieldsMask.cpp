#include "SolverFieldsMask.h"

namespace fvmsolver {

SolverFieldsMask::SolverFieldsMask(
        RecievedDataStore& store) : store_(store) {

}

double SolverFieldsMask::getU(size_t index) const {
    return store_.get_u().getValue(index);
}

double SolverFieldsMask::getV(size_t index) const { 
    return store_.get_v().getValue(index);
}

double SolverFieldsMask::getP(size_t index) const {
    return store_.get_p().getValue(index);
}


void SolverFieldsMask::setU(size_t index, double value) {
    store_.get_u().setValue(index, value);
}

void SolverFieldsMask::setV(size_t index, double value) {
    store_.get_v().setValue(index, value);
}

void SolverFieldsMask::setP(size_t index, double value) {
    store_.get_p().setValue(index, value);
}

void SolverFieldsMask::set_uCellCentered(size_t index, double value) {
    store_.get_uCellCentered().setValue(index, value);
}

void SolverFieldsMask::set_vCellCentered(size_t index, double value) {
    store_.get_vCellCentered().setValue(index, value);
}

}