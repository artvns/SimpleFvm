#include "AbstractCoeffsCalculator.h"

namespace fvmsolver {

AbstractCoeffsCalculator::AbstractCoeffsCalculator() {

}

AbstractCoeffsCalculator::~AbstractCoeffsCalculator() {
    pCellNums_ = nullptr;
    pCellTypes_ = nullptr;
    pDataExchanger_ = nullptr;
}


void AbstractCoeffsCalculator::chooseActualDomainPart(std::string partName) {

}

void AbstractCoeffsCalculator::calculateInterior(size_t id) {
    begin(id);
    calculateAdditional(id);
    calculateCoeffsWENS(id);
    setCoeffsToZero();
    calculateSource(id);
    calculateCoeffP();
    calculateRHS(id);
    end(id);
}

void AbstractCoeffsCalculator::calculateBoundary(size_t id) {
    begin(id);
    calculateAdditional(id);
    calculateCoeffsWENS(id);
    setCoeffsToZero();
    calculateSource(id);
    calculateCoeffP();
    calculateRHS(id);
    end(id);
}


void AbstractCoeffsCalculator::addCellNumsSet(
                            shPtrMapCellNumbers spCellNumsSet) {
    pCellNumsSet_ = spCellNumsSet;
}

void AbstractCoeffsCalculator::addCellTypesSet(
                            shPtrMapCellTypes spCellTypesSet) {
    pCellTypesSet_ = spCellTypesSet;
}

void AbstractCoeffsCalculator::addDataExchangerSet(
                            shPtrMapAbstractDataExchanger spDataExchangerSet) {
    pDataExchangerSet_ = spDataExchangerSet;
}


double AbstractCoeffsCalculator::getAp() {
    return a_p_; 
}

double AbstractCoeffsCalculator::getAw() {
    return a_w_; 
}

double AbstractCoeffsCalculator::getAe() {
    return a_e_; 
}

double AbstractCoeffsCalculator::getAn() {
    return a_n_; 
}

double AbstractCoeffsCalculator::getAs() {
    return a_s_; 
}

double AbstractCoeffsCalculator::getRHS() {
    return rhs_; 
}

double AbstractCoeffsCalculator::get_b() {
    return b_;
}


size_t AbstractCoeffsCalculator::get_pNum() {
    return pNum_;
}

size_t AbstractCoeffsCalculator::get_wNum() {
    return wNum_;
}

size_t AbstractCoeffsCalculator::get_eNum() {
    return eNum_;
}

size_t AbstractCoeffsCalculator::get_nNum() {
    return nNum_;
}

size_t AbstractCoeffsCalculator::get_sNum() {
    return sNum_;
}


bool AbstractCoeffsCalculator::is_wInterior() {
    return isInteriorType(wType_);
}

bool AbstractCoeffsCalculator::is_eInterior() {
    return isInteriorType(eType_);
}

bool AbstractCoeffsCalculator::is_nInterior() {
    return isInteriorType(nType_);
}

bool AbstractCoeffsCalculator::is_sInterior() {
    return isInteriorType(sType_);
}

bool AbstractCoeffsCalculator::isInteriorType(const EnumAdjacentCellTypes& type) {
    if (ADJACENT_CELL_INTERIOR == type) {
        return true;
    }
    else {
        return false;
    }
}

void AbstractCoeffsCalculator::chooseCommonComponents(std::string partName) {
    pCellNums_  = &(*pCellNumsSet_->getObject(partName));                       // Interior numbers.
    pCellTypes_ = &(*pCellTypesSet_->getObject(partName));
}

}