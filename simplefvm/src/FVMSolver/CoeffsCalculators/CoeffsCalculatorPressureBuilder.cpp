#include "CoeffsCalculatorPressureBuilder.h"

namespace fvmsolver {

CoeffsCalculatorPressureBuilder::CoeffsCalculatorPressureBuilder(
            CoeffsPartsCommonCreator& coeffsPartsCommon,
            CoeffsPartsPressureCreator& coeffsPartsPressure) :
                                coeffsPartsCommon_(coeffsPartsCommon),
                                coeffsPartsPressure_(coeffsPartsPressure) {

}

void CoeffsCalculatorPressureBuilder::createCalculator() {
    pCalculator = std::shared_ptr<CoeffsCalculatorPressure>(
        new CoeffsCalculatorPressure());
}

void CoeffsCalculatorPressureBuilder::addCellNumsSetP() {
    pCalculator->addCellNumsSet(coeffsPartsCommon_.getCellNumbersSetP());
}

void CoeffsCalculatorPressureBuilder::addCellTypesSetP() {
    pCalculator->addCellTypesSet(coeffsPartsCommon_.getCellTypesSetP());
}

void CoeffsCalculatorPressureBuilder::addCoeffsCalculator() {
    pCalculator->addCoeffsPressSet(
        coeffsPartsPressure_.getCoeffsPressSet());
}

void CoeffsCalculatorPressureBuilder::addRhsSetP() {
    pCalculator->addRhsSet(coeffsPartsPressure_.getRhsPressSet());
}

}