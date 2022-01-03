#ifndef SIMPLEFVM_FVMSOLVER_SOLVER_H
#define SIMPLEFVM_FVMSOLVER_SOLVER_H

#include <cstddef>

#include "CustomExceptions/PreparatoryOperationsException.h"
#include "DataStores/GlobalDataStores.h"
#include "FVMSolver/SolverSettings/Config.h"
#include "FVMSolver/SolverConfiguration.h"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/SolverSettings/SettingsManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/BoundaryConditions/BcManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"


namespace fvmsolver {

class Solver {
public:
    Solver(datastores::GlobalDataStores& dataStores);

    void start(const size_t numberOfIterations);

    DataManager&        getDataManager();
    SettingsManager&    getSettingsManager();
    BcManager&          getBcManager();
    MathToolsManager&   getMathToolsManager();

private:
    DataManager         dataManager_;
    BcManager           bcManager_;
    SettingsManager     settingsManager_;
    MathToolsManager    mathToolsManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVER_H