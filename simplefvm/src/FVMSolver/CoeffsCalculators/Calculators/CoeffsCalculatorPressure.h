#ifndef SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_COEFFSCALCULATORPRESSURE_H
#define SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_COEFFSCALCULATORPRESSURE_H

#include <cstddef>
#include <string>
#include <memory>

#include "AbstractCoeffsCalculator.h"
#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/CoeffsPartsCommon/CellNumbers/CellNumbers.h"
#include "FVMSolver/CoeffsPartsPressure/CoeffsPressure/CoeffsPress.h"
#include "FVMSolver/CoeffsPartsPressure/RhsPressure/RhsPress.h"


namespace fvmsolver {

class CoeffsCalculatorPressure : public AbstractCoeffsCalculator {
protected:
    using uPtrCoeffsPress = std::unique_ptr<CoeffsPress>;
    using uPtrRhsPress = std::unique_ptr<RhsPress>;
    
    using shPtrMapCoeffsPress = std::shared_ptr<MapAdt<uPtrCoeffsPress>>;
    using shPtrMapRhsPress = std::shared_ptr<MapAdt<uPtrRhsPress>>;

public:
    CoeffsCalculatorPressure();
    ~CoeffsCalculatorPressure();

    void addCoeffsPressSet(shPtrMapCoeffsPress spCoeffsPressSet);
    void addRhsSet(shPtrMapRhsPress spRhsSet);

    void chooseActualDomainPart(std::string partName) override; 

protected:
    void calculateCoeffsWENS(size_t id) override;
    void calculateCoeffP() override;
    void calculateRHS(size_t id) override;

    void begin(size_t id) override;
    void end(size_t id) override;
    void calculateAdditional(size_t id) override;
    void setCoeffsToZero() override;

private:
    CoeffsPress* pCoeffsPress_ = nullptr;
    RhsPress* pRhs_ = nullptr;

    shPtrMapCoeffsPress pCoeffsPressSet_ = nullptr;
    shPtrMapRhsPress pRhsSet_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_COEFFSCALCULATORPRESSURE_H