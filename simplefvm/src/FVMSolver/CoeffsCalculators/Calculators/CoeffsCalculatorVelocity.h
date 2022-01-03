#ifndef SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_COEFFSCALCULATORVELOCITY_H
#define SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_COEFFSCALCULATORVELOCITY_H

#include <cstddef>
#include <string>
#include <vector>
#include <iterator>
#include <memory>

#include "AbstractCoeffsCalculator.h"
#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/CoeffsPartsVelocity/DifferencingScheme/IDifferencingScheme.h"
#include "FVMSolver/CoeffsPartsVelocity/Diffusion/AbstractDiffusion.h"
#include "FVMSolver/CoeffsPartsVelocity/Flux/AbstractFlux.h"
#include "FVMSolver/CoeffsPartsVelocity/SourceTerm/AbstractSource.h"
#include "FVMSolver/CoeffsPartsVelocity/RhsVelocity/AbstractRhsVelocity.h"
#include "FVMSolver/CoeffsPartsCommon/CellNumbers/CellNumbers.h"


namespace fvmsolver {

class CoeffsCalculatorVelocity : public AbstractCoeffsCalculator {
protected:
    using uPtrAbstractDiffusion = std::unique_ptr<AbstractDiffusion>;
    using uPtrAbstractFlux = std::unique_ptr<AbstractFlux>;
    using uPtrAbstractRhsVelocity = std::unique_ptr<AbstractRhsVelocity>;
    using uPtrAbstractSource = std::unique_ptr<AbstractSource>;
    
    using shPtrIDifferencingScheme = std::shared_ptr<IDifferencingScheme>;
    using shPtrMapAbstractDiffusion = std::shared_ptr<MapAdt<uPtrAbstractDiffusion>>;
    using shPtrMapAbstractFlux = std::shared_ptr<MapAdt<uPtrAbstractFlux>>;
    using shPtrMapAbstractRhsVelocity = std::shared_ptr<MapAdt<uPtrAbstractRhsVelocity>>;
    using shPtrMapAbstractSource = std::shared_ptr<MapAdt<uPtrAbstractSource>>;

public:
    CoeffsCalculatorVelocity();
    ~CoeffsCalculatorVelocity();

    void setDifferencingScheme(shPtrIDifferencingScheme spDiffScheme);
    void addDiffusionSet(shPtrMapAbstractDiffusion spDiffusionSet);
    void addFluxSet(shPtrMapAbstractFlux spFluxSet);
    void addSourceSet(shPtrMapAbstractSource spSourceSet);
    void addRhsSet(shPtrMapAbstractRhsVelocity spRhsSet);

    void chooseActualDomainPart(std::string partName) override;   

protected:
    void calculateCoeffsWENS(size_t id) override;
    void calculateCoeffP() override;
    void calculateRHS(size_t id) override;

    void begin(size_t id) override;
    void end(size_t id) override;
    void calculateAdditional(size_t id) override;
    void calculateSource(size_t id) override;
    void setCoeffsToZero() override;

private:
    const double relaxationCoeff_ = 0.7;

    double Dw_ = 0.0;
    double De_ = 0.0;
    double Dn_ = 0.0;
    double Ds_ = 0.0;

    double Fw_ = 0.0;
    double Fe_ = 0.0;
    double Fn_ = 0.0;
    double Fs_ = 0.0;

    double Sp_ = 0.0;
    double Sc_ = 0.0;

    double deltaF_ = 0.0;

    shPtrIDifferencingScheme pDiffScheme_ = nullptr;
    AbstractDiffusion* pDiffusion_ = nullptr;
    AbstractFlux* pFlux_ = nullptr;
    AbstractSource* pSource_ = nullptr;
    AbstractRhsVelocity* pRhs_ = nullptr;

    shPtrMapAbstractDiffusion pDiffusionSet_ = nullptr;
    shPtrMapAbstractFlux pFluxSet_ = nullptr;
    shPtrMapAbstractSource pSourceSet_ = nullptr;
    shPtrMapAbstractRhsVelocity pRhsSet_ = nullptr;

    double coeffsZeroing(double a, bool isInterior);
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_COEFFSCALCULATORVELOCITY_H