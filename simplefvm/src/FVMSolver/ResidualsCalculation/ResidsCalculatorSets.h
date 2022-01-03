#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDSCALCULATORSETS_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDSCALCULATORSETS_H

#include <memory>
#include <string>
#include <map>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "IResidsCalculator.h"
#include "ResidualsCalculatorU.h"
#include "ResidualsCalculatorV.h"
#include "ResidualsCalculatorP.h"
#include "ResidualsCalculatorPorts.h"


namespace fvmsolver {

class ResidsCalculatorSets {
private:
    using shPtrMapIResidsCalculator = std::shared_ptr<MapAdt<std::unique_ptr<IResidsCalculator>>>;

public:
    ResidsCalculatorSets(
                    DataManager& dataManager,
                    MeshInfoManager& meshInfoManager,
                    MathToolsManager& mathToolsManager,
                    SolverDataStoresCreator& solverDataManager);

    shPtrMapIResidsCalculator createSetU();
    shPtrMapIResidsCalculator createSetV();
    shPtrMapIResidsCalculator createSetP();

private:
    ResidualsCalculatorPorts dataPorts_;

    SetsCreator<IResidsCalculator, ResidualsCalculatorPorts, ResidualsCalculatorU> setsMakerU_;
    SetsCreator<IResidsCalculator, ResidualsCalculatorPorts, ResidualsCalculatorV> setsMakerV_;
    SetsCreator<IResidsCalculator, ResidualsCalculatorPorts, ResidualsCalculatorP> setsMakerP_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDSCALCULATORSETS_H