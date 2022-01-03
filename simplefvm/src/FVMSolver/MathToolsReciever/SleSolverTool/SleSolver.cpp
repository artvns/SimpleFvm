#include "SleSolver.h"

namespace fvmsolver {

SleSolver::SleSolver(mathtools::ISleSolver& solver) : solver_(solver) {
    
}

void SleSolver::createContainers(const size_t cellsAmount) {
    solver_.createContainers(cellsAmount);
}

void SleSolver::placeCoeff(size_t rowPos, size_t colPos, double value) {
    solver_.placeMatrixCoeff(rowPos, colPos, value);
}

void SleSolver::placeRhsValue(size_t rowPos, double value) {
    solver_.placeRhsValue(rowPos, value);
}

void SleSolver::solve() {
    solver_.solve();
}

}