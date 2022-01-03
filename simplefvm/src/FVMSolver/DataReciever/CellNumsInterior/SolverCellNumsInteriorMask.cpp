#include "SolverCellNumsInteriorMask.h"

namespace fvmsolver {

SolverCellNumsInteriorMask::SolverCellNumsInteriorMask(
                    RecievedDataStore& store) : store_(store) {
}

size_t SolverCellNumsInteriorMask::getCellNumP(size_t index) const {
    return store_.get_CellNumP().getValue(index);
}

size_t SolverCellNumsInteriorMask::getCellNumW(size_t index) const {
    return store_.get_CellNumW().getValue(index);
}

size_t SolverCellNumsInteriorMask::getCellNumE(size_t index) const {
    return store_.get_CellNumE().getValue(index);
}

size_t SolverCellNumsInteriorMask::getCellNumN(size_t index) const {
    return store_.get_CellNumN().getValue(index);
}

size_t SolverCellNumsInteriorMask::getCellNumS(size_t index) const {
    return store_.get_CellNumS().getValue(index);
}

}