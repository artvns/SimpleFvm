#include "Solver.h"

namespace fvmsolver {

Solver::Solver(datastores::GlobalDataStores& dataStores) : 
                                        dataManager_(dataStores),
                                        bcManager_(dataManager_) {

}

void Solver::start(const size_t numberOfIterations) {
    dataManager_.createDataSetsMasks();
    dataManager_.validateRecievedData();

    bcManager_.checkBoundaryConditions();

    settingsManager_.setNumberOfIterations(numberOfIterations);
    settingsManager_.generateSolverConfig();
    settingsManager_.validateSolverConfig();

    mathToolsManager_.createScalarsStore();


    MeshInfoManager meshInfoManager_(
        dataManager_, 
        bcManager_.getPartsTypeInfo()
    );
    meshInfoManager_.createMeshInfo();


    SolverDataStoresCreator solverDataStores_(
        meshInfoManager_
    );
    solverDataStores_.createStores();


    SolverConfiguration configurator_(
        *settingsManager_.getConfig(),
        mathToolsManager_,
        dataManager_,
        bcManager_,
        solverDataStores_,
        meshInfoManager_
    );
    configurator_.configureAlgorithmComponents();
    configurator_.configureAlgorithm();
    configurator_.calculate();
}

DataManager& Solver::getDataManager() {
    return dataManager_;
}

SettingsManager& Solver::getSettingsManager() {
    return settingsManager_;
}

BcManager& Solver::getBcManager() {
    return bcManager_;
}

MathToolsManager& Solver::getMathToolsManager() {
    return mathToolsManager_;
}

}