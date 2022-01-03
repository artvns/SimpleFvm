#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORPORTS_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORPORTS_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "ResidualsCalculatorUPort.h"
#include "ResidualsCalculatorVPort.h"
#include "ResidualsCalculatorPPort.h"


namespace fvmsolver {

class ResidualsCalculatorPorts {
public:
    ResidualsCalculatorPorts(
                    DataManager& dataManager, 
                    MathToolsManager& mathToolsManager,
                    MeshInfoManager& meshInfoManager,
                    SolverDataStoresCreator& solverDataManager);

    std::unique_ptr<ResidualsCalculatorUPort> createPortU(std::string name);
    std::unique_ptr<ResidualsCalculatorVPort> createPortV(std::string name);
    std::unique_ptr<ResidualsCalculatorPPort> createPortP(std::string name);

private:
    DataManager& dataManager_;
    MathToolsManager& mathToolsManager_;
    MeshInfoManager& meshInfoManager_;
    SolverDataStoresCreator& solverDataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORPORTS_H