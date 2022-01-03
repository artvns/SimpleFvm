#include "CoeffsCalculatorCreator.h"

namespace fvmsolver {

CoeffsCalculatorCreator::CoeffsCalculatorCreator() {

}

std::shared_ptr<AbstractCoeffsCalculator> CoeffsCalculatorCreator::createForU(
                                    CoeffsCalculatorBuilder& builder) {
    builder.createCalculator();
    builder.addDataExchangerU();
    builder.addDifferencingScheme();
    builder.addDiffusionU();
    builder.addFluxU();
    builder.addSourceSetU();
    builder.addCellNumsSetU();
    builder.addCellTypesSetU();
    builder.addRhsSetU();
    return builder.getCoeffCalculator();
}

std::shared_ptr<AbstractCoeffsCalculator> CoeffsCalculatorCreator::createForV(
                                    CoeffsCalculatorBuilder& builder) {
    builder.createCalculator();
    builder.addDataExchangerV();
    builder.addDifferencingScheme();
    builder.addDiffusionV();
    builder.addFluxV();
    builder.addSourceSetV();
    builder.addCellNumsSetV();
    builder.addCellTypesSetV();
    builder.addRhsSetV();
    return builder.getCoeffCalculator();
}

std::shared_ptr<AbstractCoeffsCalculator> CoeffsCalculatorCreator::createForP(
                                    CoeffsCalculatorBuilder& builder) {
    builder.createCalculator();
    builder.addCoeffsCalculator();
    builder.addRhsSetP();
    builder.addCellNumsSetP();
    builder.addCellTypesSetP();
    return builder.getCoeffCalculator();
}

}