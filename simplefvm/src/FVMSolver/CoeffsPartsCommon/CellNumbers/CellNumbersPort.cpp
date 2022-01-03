#include "CellNumbersPort.h"

namespace fvmsolver {

CellNumbersPort::CellNumbersPort(
                const SolverCellNumsInteriorMask& nums) : nums_(nums) {

}

size_t CellNumbersPort::get_pNum(size_t step) const {
    return nums_.getCellNumP(step);
}

size_t CellNumbersPort::get_wNum(size_t step) const {
    return nums_.getCellNumW(step);
}

size_t CellNumbersPort::get_eNum(size_t step) const {
    return nums_.getCellNumE(step);
}

size_t CellNumbersPort::get_nNum(size_t step) const {
    return nums_.getCellNumN(step);
}

size_t CellNumbersPort::get_sNum(size_t step) const {
    return nums_.getCellNumS(step);
}

}