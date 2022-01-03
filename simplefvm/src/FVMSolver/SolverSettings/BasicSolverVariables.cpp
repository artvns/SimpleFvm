#include "BasicSolverVariables.h"

namespace fvmsolver {

BasicSolverVariables::BasicSolverVariables() {

}

void BasicSolverVariables::setDxDyValue(const double value) {
    dimentionDxDy_ = value;
}

double BasicSolverVariables::getDxDyValue() const {
    return dimentionDxDy_;
}

void BasicSolverVariables::setResidualsFullFileName(const std::string fullFileName) {
    fullFileName_ = fullFileName;
}

std::string BasicSolverVariables::getResidualsFullFileName() const {
    return fullFileName_;
}

void BasicSolverVariables::setNumberOfIterations(const size_t iterations) {
    numberOfIterations_ = iterations;
}

size_t BasicSolverVariables::getNumberOfIterations() const {
    return numberOfIterations_; 
}

}