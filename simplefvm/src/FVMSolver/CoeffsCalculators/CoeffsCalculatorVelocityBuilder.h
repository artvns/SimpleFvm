#ifndef SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORVELOCITYBUILDER_H
#define SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORVELOCITYBUILDER_H

#include <vector>
#include <memory>

#include "FVMSolver/CoeffsPartsCommon/CoeffsPartsCommonCreator.h"
#include "FVMSolver/CoeffsPartsVelocity/CoeffsPartsVelocityCreator.h"
#include "FVMSolver/CoeffsCalculators/Calculators/AbstractCoeffsCalculator.h"
#include "FVMSolver/CoeffsCalculators/Calculators/CoeffsCalculatorVelocity.h"
#include "FVMSolver/CoeffsCalculators/CoeffsCalculatorBuilder.h"


namespace fvmsolver {

class CoeffsCalculatorVelocityBuilder : public CoeffsCalculatorBuilder {
public:
    CoeffsCalculatorVelocityBuilder(
            CoeffsPartsCommonCreator& coeffsPartsCommon,
            CoeffsPartsVelocityCreator& coeffsPartsVelocity);

    void createCalculator() override;
    void addDataExchangerU() override;
    void addDataExchangerV() override;
    void addDifferencingScheme() override;
    void addDiffusionU() override;
    void addDiffusionV() override;
    void addFluxU() override;
    void addFluxV() override;
    void addSourceSetU() override;
    void addSourceSetV() override;
    void addCellNumsSetU() override;
    void addCellNumsSetV() override;
    void addCellTypesSetU() override;
    void addCellTypesSetV() override;
    void addRhsSetU() override;
    void addRhsSetV() override;

    std::shared_ptr<AbstractCoeffsCalculator> getCoeffCalculator() override { 
        return pCalculator; 
    }

private:
    CoeffsPartsCommonCreator& coeffsPartsCommon_;
    CoeffsPartsVelocityCreator& coeffsPartsVelocity_;

    std::shared_ptr<CoeffsCalculatorVelocity> pCalculator = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORVELOCITYBUILDER_H