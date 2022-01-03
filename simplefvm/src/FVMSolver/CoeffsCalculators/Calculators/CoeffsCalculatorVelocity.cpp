#include "CoeffsCalculatorVelocity.h"

namespace fvmsolver {

CoeffsCalculatorVelocity::CoeffsCalculatorVelocity() {

}

CoeffsCalculatorVelocity::~CoeffsCalculatorVelocity() {
    pDiffusion_ = nullptr;
    pFlux_ = nullptr;
    pSource_ = nullptr;
    pRhs_ = nullptr;
}

void CoeffsCalculatorVelocity::chooseActualDomainPart(std::string partName) {
    chooseCommonComponents(partName);
    
    pDataExchanger_ = &(*pDataExchangerSet_->getObject(partName));

    pDiffusion_ = &(*pDiffusionSet_->getObject(partName));
    pFlux_ = &(*pFluxSet_->getObject(partName));
    pSource_ = &(*pSourceSet_->getObject(partName));
    pRhs_ = &(*pRhsSet_->getObject(partName));
}

void CoeffsCalculatorVelocity::calculateAdditional(size_t id) {
    pDiffusion_->calculate(id);
    Dw_ = pDiffusion_->getDw();
    De_ = pDiffusion_->getDe();
    Dn_ = pDiffusion_->getDn();
    Ds_ = pDiffusion_->getDs();
    
    pFlux_->calculate(id);
    Fw_ = pFlux_->getFw();
    Fe_ = pFlux_->getFe();
    Fn_ = pFlux_->getFn();
    Fs_ = pFlux_->getFs();


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


void CoeffsCalculatorVelocity::calculateCoeffsWENS(size_t id) {
    a_w_ = pDiffScheme_->a_w(Dw_, Fw_);
    a_e_ = pDiffScheme_->a_e(De_, Fe_);
    a_n_ = pDiffScheme_->a_n(Dn_, Fn_);
    a_s_ = pDiffScheme_->a_s(Ds_, Fs_);
    deltaF_ = pDiffScheme_->deltaF(Fw_, Fe_, Fs_, Fn_);
}

void CoeffsCalculatorVelocity::setCoeffsToZero() {
    a_w_ = coeffsZeroing(a_w_, isInteriorType(wType_));
    a_e_ = coeffsZeroing(a_e_, isInteriorType(eType_));
    a_n_ = coeffsZeroing(a_n_, isInteriorType(nType_));
    a_s_ = coeffsZeroing(a_s_, isInteriorType(sType_));
}

void CoeffsCalculatorVelocity::calculateCoeffP() {
    a_p_ = a_w_ + a_e_ + a_n_ + a_s_ + deltaF_ + Sp_;
}

void CoeffsCalculatorVelocity::calculateRHS(size_t id) {
    pRhs_->calculate(id, Sc_, a_p_);
    rhs_ = pRhs_->getRhsValue();
    b_ = pRhs_->get_bValue();
}

void CoeffsCalculatorVelocity::begin(size_t id) {

}

void CoeffsCalculatorVelocity::end(size_t id) {
    a_p_ = a_p_ / relaxationCoeff_;
    pDataExchanger_->add_de(id, a_p_);
}

void CoeffsCalculatorVelocity::calculateSource(size_t id) {
    pSource_->calculate(id);
    Sp_ = pSource_->getSp();
    Sc_ = pSource_->getSc();
}

void CoeffsCalculatorVelocity::setDifferencingScheme(shPtrIDifferencingScheme spDiffScheme) {
    pDiffScheme_ = spDiffScheme;
}

void CoeffsCalculatorVelocity::addDiffusionSet(shPtrMapAbstractDiffusion spDiffusionSet) {
    pDiffusionSet_ = spDiffusionSet;
}

void CoeffsCalculatorVelocity::addFluxSet(shPtrMapAbstractFlux spFluxSet) {
    pFluxSet_ = spFluxSet;
}

void CoeffsCalculatorVelocity::addSourceSet(shPtrMapAbstractSource spSourceSet) {
    pSourceSet_ = spSourceSet;
}

void CoeffsCalculatorVelocity::addRhsSet(shPtrMapAbstractRhsVelocity spRhsSet) {
    pRhsSet_ = spRhsSet;
}

double CoeffsCalculatorVelocity::coeffsZeroing(double a, bool isInterior) {
    if(!isInterior) {
        return 0.0;
    }
    else {
        return a;
    }
}

}