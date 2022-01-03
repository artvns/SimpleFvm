#include "Simple.h"

namespace fvmsolver {

Simple::Simple() {

}

void Simple::executeAlgorithmSteps() {
    solveMomentumEquations();
    solvePressureCorrectionEquation();
    correctFields();
    calculateResiduals();
    outputResiduals();
}

void Simple::solveMomentumEquations() {
    pUStarCalculator_->calculate();
    pVStarCalculator_->calculate();
}

void Simple::solvePressureCorrectionEquation() {
    pPressCalculator_->calculate();
}

void Simple::calculateResiduals() {
    pResidCalculatorP_->calculateResidual();
    pResidCalculatorU_->calculateResidual();
    pResidCalculatorV_->calculateResidual();
}


void Simple::outputResiduals() {
    pResidOutputer_->addStepResidualU(pResidCalculatorU_->getResidual());
    pResidOutputer_->addStepResidualV(pResidCalculatorV_->getResidual());
    pResidOutputer_->addStepResidualP(pResidCalculatorP_->getResidual());

    pResidOutputer_->saveStepResiduals(calculationStep_);
}


void Simple::correctFields() {
    pFieldCorrectorU_->correctField();
    pFieldCorrectorV_->correctField();
    pFieldCorrectorP_->correctField();
}

void Simple::setUVariableCalculator(std::shared_ptr<ScalarCalculator> sle) {
    pUStarCalculator_ = sle;
}

void Simple::setVVariableCalculator(std::shared_ptr<ScalarCalculator> sle) {
    pVStarCalculator_ = sle;
}

void Simple::setPressVariableCalculator(std::shared_ptr<ScalarCalculator> sle) { 
    pPressCalculator_ = sle;
}

void Simple::setFieldsCorrectorP(std::shared_ptr<FieldCorrector> corrector) {
    pFieldCorrectorP_ = corrector;
}

void Simple::setFieldsCorrectorU(std::shared_ptr<FieldCorrector> corrector) {
    pFieldCorrectorU_ = corrector;
}

void Simple::setFieldsCorrectorV(std::shared_ptr<FieldCorrector> corrector) {
    pFieldCorrectorV_ = corrector;
}

void Simple::setResidualsCalculatorP(std::shared_ptr<ResidualsCalculator> residualsCalc) {
    pResidCalculatorP_ = residualsCalc;
}

void Simple::setResidualsCalculatorU(std::shared_ptr<ResidualsCalculator> residualsCalc) {
    pResidCalculatorU_ = residualsCalc;
}

void Simple::setResidualsCalculatorV(std::shared_ptr<ResidualsCalculator> residualsCalc) {
    pResidCalculatorV_ = residualsCalc;
}

void Simple::setResidualsOutputer(std::shared_ptr<ResidualsOutputer> residsOutputer) {
    pResidOutputer_ = residsOutputer;
}

}