#include "SolverCellNumsGlobalMask.h"

namespace fvmsolver {

SolverCellNumsGlobalMask::SolverCellNumsGlobalMask(
                RecievedDataStore& store) : store_(store) {

}

size_t SolverCellNumsGlobalMask::get_pCellNum(size_t index) const {
    return store_.get_pCellNum().getValue(index);
}

size_t SolverCellNumsGlobalMask::get_wCellNum(size_t index) const {
    return store_.get_wCellNum().getValue(index);
}

size_t SolverCellNumsGlobalMask::get_eCellNum(size_t index) const {
    return store_.get_eCellNum().getValue(index);
}

size_t SolverCellNumsGlobalMask::get_nCellNum(size_t index) const {
    return store_.get_nCellNum().getValue(index);
}

size_t SolverCellNumsGlobalMask::get_sCellNum(size_t index) const {
    return store_.get_sCellNum().getValue(index);
}

}