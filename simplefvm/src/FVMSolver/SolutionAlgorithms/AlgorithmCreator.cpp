#include "AlgorithmCreator.h"

namespace fvmsolver {

AlgorithmCreator::AlgorithmCreator() {

}

std::shared_ptr<AbstractAlgorithm> AlgorithmCreator::createSimple2D(
                                            AlgorithmBuilder& builder) {
    builder.createAlgorithm();
    builder.addNumberOfIterations();
    builder.addCalculatorUstar();
    builder.addCalculatorVstar();
    builder.addCalculatorPprime();
    builder.addCorrectorU();
    builder.addCorrectorV();
    builder.addCorrectorP();
    builder.addResidualsCalculatorU();
    builder.addResidualsCalculatorV();
    builder.addResidualsCalculatorP();
    builder.addResidualsOutput();
    return builder.getAlgorithm();
}

std::shared_ptr<AbstractAlgorithm> AlgorithmCreator::createSimple1D(
                                            AlgorithmBuilder& builder) {
    builder.createAlgorithm();
    builder.addNumberOfIterations();
    builder.addCalculatorUstar();
    builder.addCalculatorPprime();
    builder.addCorrectorU();
    builder.addCorrectorP();
    builder.addResidualsCalculatorU();
    builder.addResidualsCalculatorP();
    builder.addResidualsOutput();
    return builder.getAlgorithm();
}

}