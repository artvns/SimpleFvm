#ifndef SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORPRESSUREBUILDER_H
#define SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORPRESSUREBUILDER_H

#include <memory>

#include "FVMSolver/CoeffsPartsCommon/CoeffsPartsCommonCreator.h"
#include "FVMSolver/CoeffsPartsPressure/CoeffsPartsPressureCreator.h"
#include "FVMSolver/CoeffsCalculators/Calculators/AbstractCoeffsCalculator.h"
#include "FVMSolver/CoeffsCalculators/Calculators/CoeffsCalculatorPressure.h"
#include "FVMSolver/CoeffsCalculators/CoeffsCalculatorBuilder.h"


namespace fvmsolver {

class CoeffsCalculatorPressureBuilder : public CoeffsCalculatorBuilder {
public:
    CoeffsCalculatorPressureBuilder(
            CoeffsPartsCommonCreator& coeffsPartsCommon,
            CoeffsPartsPressureCreator& coeffsPartsPressure);

    void addCellNumsSetP() override;
    void addCellTypesSetP() override;
    void addCoeffsCalculator() override;
    void addRhsSetP() override;

    void createCalculator() override;
    std::shared_ptr<AbstractCoeffsCalculator> getCoeffCalculator() override { 
        return pCalculator; 
    }

private:
    CoeffsPartsCommonCreator& coeffsPartsCommon_;
    CoeffsPartsPressureCreator& coeffsPartsPressure_;

    std::shared_ptr<CoeffsCalculatorPressure> pCalculator = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORPRESSUREBUILDER_H