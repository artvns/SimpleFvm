#include "AlgorithmBuilderSimple.h"

namespace fvmsolver {

AlgorithmBuilderSimple::AlgorithmBuilderSimple(
        Config& config,
        ScalarCalculatorCreator& sleCalculatorCreator,
        FieldsCorrectorsCreator& fieldsCorrectorsCreator,
        ResidsCalculatorsCreator& residsCalculatorsCreator,
        ResidsOutputerCreator& residsOutputerCreator) : 
                    config_(config),
                    sleCalculatorCreator_(sleCalculatorCreator),
                    fieldsCorrectorsCreator_(fieldsCorrectorsCreator),
                    residsCalculatorsCreator_(residsCalculatorsCreator),
                    residsOutputerCreator_(residsOutputerCreator) {

}

void AlgorithmBuilderSimple::createAlgorithm() {
    pAlgorithm_ = std::shared_ptr<Simple>(new Simple());
}

void AlgorithmBuilderSimple::addNumberOfIterations() {
    pAlgorithm_->setNumberOfIterations(
        config_.basicSolverVariables.getNumberOfIterations());
}

void AlgorithmBuilderSimple::addCalculatorUstar() {
    pAlgorithm_->setUVariableCalculator(
        sleCalculatorCreator_.createUStarCalculator());
}

void AlgorithmBuilderSimple::addCalculatorVstar() {
    pAlgorithm_->setVVariableCalculator(
        sleCalculatorCreator_.createVStarCalculator());
}

void AlgorithmBuilderSimple::addCalculatorPprime() {
    pAlgorithm_->setPressVariableCalculator(
        sleCalculatorCreator_.createPPrimeCalculator());
}

void AlgorithmBuilderSimple::addCorrectorU() {
    pAlgorithm_->setFieldsCorrectorU(
        fieldsCorrectorsCreator_.createFiledCorrectorU());
}

void AlgorithmBuilderSimple::addCorrectorV() {
    pAlgorithm_->setFieldsCorrectorV(
        fieldsCorrectorsCreator_.createFiledCorrectorV());
}

void AlgorithmBuilderSimple::addCorrectorP() {
    pAlgorithm_->setFieldsCorrectorP(
        fieldsCorrectorsCreator_.createFiledCorrectorP());
}

void AlgorithmBuilderSimple::addResidualsCalculatorU() {
    pAlgorithm_->setResidualsCalculatorU(
        residsCalculatorsCreator_.createResidsCalculatorU());
}

void AlgorithmBuilderSimple::addResidualsCalculatorV() {
    pAlgorithm_->setResidualsCalculatorV(
        residsCalculatorsCreator_.createResidsCalculatorV());
}

void AlgorithmBuilderSimple::addResidualsCalculatorP() {
    pAlgorithm_->setResidualsCalculatorP(
        residsCalculatorsCreator_.createResidsCalculatorP());
}

void AlgorithmBuilderSimple::addResidualsOutput() {
    pAlgorithm_->setResidualsOutputer(
        residsOutputerCreator_.createResidsOutputer());
}

}