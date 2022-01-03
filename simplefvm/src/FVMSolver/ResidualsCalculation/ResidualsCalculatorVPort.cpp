#include "ResidualsCalculatorVPort.h"

namespace fvmsolver {

ResidualsCalculatorVPort::ResidualsCalculatorVPort(
                const SolverCellNumsInteriorMask& numsInterior,
                ScalarsStore& scalar,
                SavedCoeffsStore& savedCoeffs,
                SavedRhsStore& savedRhs) : 
                                numsInterior_(numsInterior),
                                scalar_(scalar),
                                savedCoeffs_(savedCoeffs),
                                savedRhs_(savedRhs) {

}

CalculatedScalar& ResidualsCalculatorVPort::getVStar() {
    return scalar_.get_vStar();
}

size_t ResidualsCalculatorVPort::getInterNumVp(const size_t step) const {
    return numsInterior_.getCellNumP(step);
}

size_t ResidualsCalculatorVPort::getInterNumVw(const size_t step) const {
    return numsInterior_.getCellNumW(step);
}

size_t ResidualsCalculatorVPort::getInterNumVe(const size_t step) const {
    return numsInterior_.getCellNumE(step);
}

size_t ResidualsCalculatorVPort::getInterNumVn(const size_t step) const {
    return numsInterior_.getCellNumN(step);
}

size_t ResidualsCalculatorVPort::getInterNumVs(const size_t step) const {
    return numsInterior_.getCellNumS(step);
}

std::vector<double>& ResidualsCalculatorVPort::getAp() {
    return savedCoeffs_.getAp();
}

std::vector<double>& ResidualsCalculatorVPort::getAw() {
    return savedCoeffs_.getAw();
}

std::vector<double>& ResidualsCalculatorVPort::getAe() {
    return savedCoeffs_.getAe();
}

std::vector<double>& ResidualsCalculatorVPort::getAn() {
    return savedCoeffs_.getAn();
}

std::vector<double>& ResidualsCalculatorVPort::getAs() {
    return savedCoeffs_.getAs();
}

double ResidualsCalculatorVPort::get_b(const size_t pos) const {
    return savedRhs_.get_b(pos);
}

}