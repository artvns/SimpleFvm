#include "AbstractAlgorithm.h"

namespace fvmsolver {

AbstractAlgorithm::AbstractAlgorithm() {

}

AbstractAlgorithm::~AbstractAlgorithm() {
    
}

void AbstractAlgorithm::calculate() {
    while (calculationStep_ < numberOfIterations_) {
        executeAlgorithmSteps();
        calculationStep_++;
    }
}

void AbstractAlgorithm::setNumberOfIterations(const size_t iterations) {
    numberOfIterations_ = iterations;
}

}