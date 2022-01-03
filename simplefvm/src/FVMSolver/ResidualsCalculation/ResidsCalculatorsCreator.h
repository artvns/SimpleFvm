#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDSCALCULATORSCREATOR_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDSCALCULATORSCREATOR_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/ResidualsCalculation/ResidualsCalculator.h"
#include "FVMSolver/ResidualsCalculation/ResidsCalculatorSets.h"


namespace fvmsolver {

class ResidsCalculatorsCreator {
public:
    ResidsCalculatorsCreator(
                        DataManager& dataManager, 
                        MeshInfoManager& meshInfoManager,
                        MathToolsManager& mathToolsManager,
                        SolverDataStoresCreator& solverDataManager);

    std::shared_ptr<ResidualsCalculator> createResidsCalculatorU();
    std::shared_ptr<ResidualsCalculator> createResidsCalculatorV();
    std::shared_ptr<ResidualsCalculator> createResidsCalculatorP();

private:
    ResidsCalculatorSets residCalculatorSets_;
    MeshInfoManager& meshInfoManager_;

    std::shared_ptr<ResidualsCalculator> spResidsCalculatorU_ = nullptr;
    std::shared_ptr<ResidualsCalculator> spResidsCalculatorV_ = nullptr;
    std::shared_ptr<ResidualsCalculator> spResidsCalculatorP_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDSCALCULATORSCREATOR_H