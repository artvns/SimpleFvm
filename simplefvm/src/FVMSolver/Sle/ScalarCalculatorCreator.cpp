#include "ScalarCalculatorCreator.h"

namespace fvmsolver {

ScalarCalculatorCreator::ScalarCalculatorCreator(
            MathToolsManager& mathToolsManager, 
            SleMatrixBuilderCreator& sleMatrixBuilderCreator) :
                    mathToolsManager_(mathToolsManager),
                    sleMatrixBuilderCreator_(sleMatrixBuilderCreator) {

}

std::shared_ptr<ScalarCalculator> ScalarCalculatorCreator::createUStarCalculator() {
    return std::shared_ptr<ScalarCalculator>(
            new ScalarCalculator(
                mathToolsManager_.getSleSoverU(),
                sleMatrixBuilderCreator_.createUStarBuilder()));
}

std::shared_ptr<ScalarCalculator> ScalarCalculatorCreator::createVStarCalculator() {
    return std::shared_ptr<ScalarCalculator>(
            new ScalarCalculator(
                mathToolsManager_.getSleSoverV(),
                sleMatrixBuilderCreator_.createVStarBuilder()));
}

std::shared_ptr<ScalarCalculator> ScalarCalculatorCreator::createPPrimeCalculator() {
    return std::shared_ptr<ScalarCalculator>(
            new ScalarCalculator(
                mathToolsManager_.getSleSoverP(),
                sleMatrixBuilderCreator_.createPPrimeBuilder()));
}

}