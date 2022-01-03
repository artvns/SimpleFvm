#include "CoeffsCalculatorVelocityBuilder.h"

namespace fvmsolver {

CoeffsCalculatorVelocityBuilder::CoeffsCalculatorVelocityBuilder(
        CoeffsPartsCommonCreator& coeffsPartsCommon,
        CoeffsPartsVelocityCreator& coeffsPartsVelocity) :
                            coeffsPartsCommon_(coeffsPartsCommon),
                            coeffsPartsVelocity_(coeffsPartsVelocity) {

}

void CoeffsCalculatorVelocityBuilder::createCalculator() {
    pCalculator = std::shared_ptr<CoeffsCalculatorVelocity>(
        new CoeffsCalculatorVelocity());
}

void CoeffsCalculatorVelocityBuilder::addDataExchangerU() {
    pCalculator->addDataExchangerSet(
        coeffsPartsCommon_.getDataExchangerSetU());
}

void CoeffsCalculatorVelocityBuilder::addDataExchangerV() {
    pCalculator->addDataExchangerSet(
        coeffsPartsCommon_.getDataExchangerSetV());
}

void CoeffsCalculatorVelocityBuilder::addDifferencingScheme() {
    pCalculator->setDifferencingScheme(
        coeffsPartsVelocity_.getDifferencingScheme());
}

void CoeffsCalculatorVelocityBuilder::addDiffusionU() {
    pCalculator->addDiffusionSet(coeffsPartsVelocity_.getDiffusionSetU());
}

void CoeffsCalculatorVelocityBuilder::addDiffusionV() {
    pCalculator->addDiffusionSet(coeffsPartsVelocity_.getDiffusionSetV());
}

void CoeffsCalculatorVelocityBuilder::addFluxU() {
    pCalculator->addFluxSet(coeffsPartsVelocity_.getFluxSetU());
}

void CoeffsCalculatorVelocityBuilder::addFluxV() {
    pCalculator->addFluxSet(coeffsPartsVelocity_.getFluxSetV());
}

void CoeffsCalculatorVelocityBuilder::addSourceSetU() {
    pCalculator->addSourceSet(coeffsPartsVelocity_.getSourceSetU());
}

void CoeffsCalculatorVelocityBuilder::addSourceSetV() {
    pCalculator->addSourceSet(coeffsPartsVelocity_.getSourceSetV());
}

void CoeffsCalculatorVelocityBuilder::addCellNumsSetU() {
    pCalculator->addCellNumsSet(coeffsPartsCommon_.getCellNumbersSetU());
}

void CoeffsCalculatorVelocityBuilder::addCellNumsSetV() {
    pCalculator->addCellNumsSet(coeffsPartsCommon_.getCellNumbersSetV());
}

void CoeffsCalculatorVelocityBuilder::addCellTypesSetU() {
    pCalculator->addCellTypesSet(coeffsPartsCommon_.getCellTypesSetU());
}

void CoeffsCalculatorVelocityBuilder::addCellTypesSetV() {
    pCalculator->addCellTypesSet(coeffsPartsCommon_.getCellTypesSetV());
}

void CoeffsCalculatorVelocityBuilder::addRhsSetU() {
    pCalculator->addRhsSet(coeffsPartsVelocity_.getRhsSetU());
}

void CoeffsCalculatorVelocityBuilder::addRhsSetV() {
    pCalculator->addRhsSet(coeffsPartsVelocity_.getRhsSetV());
}

}