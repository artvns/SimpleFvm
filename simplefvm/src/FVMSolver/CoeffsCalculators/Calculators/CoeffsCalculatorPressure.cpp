#include "CoeffsCalculatorPressure.h"

namespace fvmsolver {

CoeffsCalculatorPressure::CoeffsCalculatorPressure() {

}

CoeffsCalculatorPressure::~CoeffsCalculatorPressure() {
    pCoeffsPress_ = nullptr;
    pRhs_ = nullptr;
}

void CoeffsCalculatorPressure::chooseActualDomainPart(std::string partName) {
    chooseCommonComponents(partName);

    pCoeffsPress_ = &(*pCoeffsPressSet_->getObject(partName));
    pRhs_ = &(*pRhsSet_->getObject(partName));
}

void CoeffsCalculatorPressure::calculateCoeffsWENS(size_t id) {
    pCoeffsPress_->calculate(id);
    a_w_ = pCoeffsPress_->getAw();
    a_e_ = pCoeffsPress_->getAe();
    a_n_ = pCoeffsPress_->getAn();
    a_s_ = pCoeffsPress_->getAs();
}

void CoeffsCalculatorPressure::calculateCoeffP() {
    a_p_ = a_w_ + a_e_ + a_n_ + a_s_;
}

void CoeffsCalculatorPressure::calculateRHS(size_t id) {
    pRhs_->calculate(id);
    rhs_ = pRhs_->getRhsValue();
}

void CoeffsCalculatorPressure::begin(size_t id) {

}

void CoeffsCalculatorPressure::end(size_t id) {
    pCellNums_->assignCurrentCellValues(id);
    pNum_ = pCellNums_->get_pNum();
    wNum_ = pCellNums_->get_wNum();
    eNum_ = pCellNums_->get_eNum();
    nNum_ = pCellNums_->get_nNum();
    sNum_ = pCellNums_->get_sNum();

    pCellTypes_->assignCurrentCellValues(id);
    wType_ = pCellTypes_->get_wType();
    eType_ = pCellTypes_->get_eType();
    nType_ = pCellTypes_->get_nType();
    sType_ = pCellTypes_->get_sType();
}

void CoeffsCalculatorPressure::calculateAdditional(size_t id) {

}

void CoeffsCalculatorPressure::setCoeffsToZero() {

}

void CoeffsCalculatorPressure::addCoeffsPressSet(shPtrMapCoeffsPress spCoeffsPressSet) {
    pCoeffsPressSet_ = spCoeffsPressSet;

}

void CoeffsCalculatorPressure::addRhsSet(shPtrMapRhsPress spRhsSet) {
    pRhsSet_ = spRhsSet;
}

}