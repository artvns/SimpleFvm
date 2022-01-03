#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATOR_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATOR_H

#include <cstddef>
#include <cmath>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/MeshInformation/MeshInfo.h"

#include "IResidsCalculator.h"


namespace fvmsolver {

class ResidualsCalculator {
public:
    ResidualsCalculator(
            MeshInfo& meshInfo, 
            std::shared_ptr<MapAdt<std::unique_ptr<IResidsCalculator>>> residCalculatorSet);

    void calculateResidual();
    double getResidual();

private:
    MeshInfo& meshInfo_;
    std::shared_ptr<MapAdt<std::unique_ptr<IResidsCalculator>>> residCalculatorSet_;

    double maxResidual_ = 0.0;
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATOR_H