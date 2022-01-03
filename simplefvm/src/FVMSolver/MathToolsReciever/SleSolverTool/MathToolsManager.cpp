#include "MathToolsManager.h"

namespace fvmsolver {

MathToolsManager::MathToolsManager() {
    
}

void MathToolsManager::createScalarsStore() {
    pScalarsStore_ =  std::shared_ptr<ScalarsStore>(
        new ScalarsStore(*pResVectorU_, *pResVectorV_, *pResVectorP_));
}

std::shared_ptr<ScalarsStore> MathToolsManager::getScalarsStore() {
    return pScalarsStore_;  
}

std::shared_ptr<SleSolver> MathToolsManager::getSleSoverP() {
    return pSleSolverP_;
}

std::shared_ptr<SleSolver> MathToolsManager::getSleSoverU() {
    return pSleSolverU_;
}

std::shared_ptr<SleSolver> MathToolsManager::getSleSoverV() {
    return pSleSolverV_;
}

void MathToolsManager::setSleSoverP(mathtools::ISleSolver& solver) {
    pSleSolverP_ = std::shared_ptr<SleSolver>(new SleSolver(solver));
    pResVectorP_ = std::shared_ptr<CalculatedScalar>(
        new CalculatedScalar(solver.getResultsVector()));
}

void MathToolsManager::setSleSoverU(mathtools::ISleSolver& solver) {
    pSleSolverU_ = std::shared_ptr<SleSolver>(new SleSolver(solver));
    pResVectorU_ = std::shared_ptr<CalculatedScalar>(
        new CalculatedScalar(solver.getResultsVector()));
}

void MathToolsManager::setSleSoverV(mathtools::ISleSolver& solver) {
    pSleSolverV_ = std::shared_ptr<SleSolver>(new SleSolver(solver));
    pResVectorV_ = std::shared_ptr<CalculatedScalar>(
        new CalculatedScalar(solver.getResultsVector()));
}

}