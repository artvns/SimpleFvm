#include "ResidualsCalculatorUPort.h"

namespace fvmsolver {

ResidualsCalculatorUPort::ResidualsCalculatorUPort(
                const SolverCellNumsInteriorMask& numsInterior,
                ScalarsStore& scalar,
                SavedCoeffsStore& savedCoeffs,
                SavedRhsStore& savedRhs) : 
                                numsInterior_(numsInterior),
                                scalar_(scalar),
                                savedCoeffs_(savedCoeffs),
                                savedRhs_(savedRhs) {

}

CalculatedScalar& ResidualsCalculatorUPort::getUStar() {
    return scalar_.get_uStar();
}

size_t ResidualsCalculatorUPort::getInterNumUp(const size_t step) const {
    return numsInterior_.getCellNumP(step);
}

size_t ResidualsCalculatorUPort::getInterNumUw(const size_t step) const {
    return numsInterior_.getCellNumW(step);
}

size_t ResidualsCalculatorUPort::getInterNumUe(const size_t step) const {
    return numsInterior_.getCellNumE(step);
}

size_t ResidualsCalculatorUPort::getInterNumUn(const size_t step) const {
    return numsInterior_.getCellNumN(step);
}

size_t ResidualsCalculatorUPort::getInterNumUs(const size_t step) const {
    return numsInterior_.getCellNumS(step);
}

std::vector<double>& ResidualsCalculatorUPort::getAp() {
    return savedCoeffs_.getAp();
}

std::vector<double>& ResidualsCalculatorUPort::getAw() {
    return savedCoeffs_.getAw();
}

std::vector<double>& ResidualsCalculatorUPort::getAe() {
    return savedCoeffs_.getAe();
}

std::vector<double>& ResidualsCalculatorUPort::getAn() {
    return savedCoeffs_.getAn();
}

std::vector<double>& ResidualsCalculatorUPort::getAs() {
    return savedCoeffs_.getAs();
}

double ResidualsCalculatorUPort::get_b(const size_t pos) const {
    return savedRhs_.get_b(pos);
}

}