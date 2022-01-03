#ifndef SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORBUILDER_H
#define SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORBUILDER_H

#include <iostream>
#include <memory>

#include "FVMSolver/CoeffsCalculators/Calculators/AbstractCoeffsCalculator.h"


namespace fvmsolver {

class CoeffsCalculatorBuilder {
public:
    CoeffsCalculatorBuilder() {}
    virtual ~CoeffsCalculatorBuilder() {}

    virtual void createCalculator() {}
    virtual void addCoeffsCalculator() {}
    virtual void addDataExchangerU() {}
    virtual void addDataExchangerV() {}
    virtual void addDataExchangerP() {}
    virtual void addDifferencingScheme() {}
    virtual void addDiffusionU() {}
    virtual void addDiffusionV() {}
    virtual void addFluxU() {}
    virtual void addFluxV() {}
    virtual void addSourceSetU() {}
    virtual void addSourceSetV() {}
    virtual void addCellNumsSetU() {}
    virtual void addCellNumsSetV() {}
    virtual void addCellNumsSetP() {}
    virtual void addCellTypesSetU() {}
    virtual void addCellTypesSetV() {}
    virtual void addCellTypesSetP() {}
    virtual void addRhsSetU() {}
    virtual void addRhsSetV() {}
    virtual void addRhsSetP() {}

    virtual std::shared_ptr<AbstractCoeffsCalculator> getCoeffCalculator() { 
        return std::move(pCalculator); 
    }

protected:
    std::shared_ptr<AbstractCoeffsCalculator> pCalculator = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORBUILDER_H