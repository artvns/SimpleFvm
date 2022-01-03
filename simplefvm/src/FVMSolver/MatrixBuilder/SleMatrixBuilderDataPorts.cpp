#include "SleMatrixBuilderDataPorts.h"


namespace fvmsolver {

SleMatrixBuilderDataPorts::SleMatrixBuilderDataPorts(
                        MeshInfoManager& meshInfoManager,
                        SolverDataStoresCreator& solverDataStores) :
                                    meshInfoManager_(meshInfoManager),
                                    solverDataStores_(solverDataStores) {

}

std::unique_ptr<SleMatrixBuilderPort> SleMatrixBuilderDataPorts::createPortU() {
    return std::move(
        std::unique_ptr<SleMatrixBuilderPort>(
            new SleMatrixBuilderPort(
                *meshInfoManager_.getMeshInfoU(),
                solverDataStores_.getSavedCoeffsStoreU(),
                solverDataStores_.getSavedRhsStoreU())));
}

std::unique_ptr<SleMatrixBuilderPort> SleMatrixBuilderDataPorts::createPortV() {
    return std::move(
        std::unique_ptr<SleMatrixBuilderPort>(
            new SleMatrixBuilderPort(
                *meshInfoManager_.getMeshInfoV(),
                solverDataStores_.getSavedCoeffsStoreV(),
                solverDataStores_.getSavedRhsStoreV())));
}

std::unique_ptr<SleMatrixBuilderPort> SleMatrixBuilderDataPorts::createPortP() {
    return std::move(
        std::unique_ptr<SleMatrixBuilderPort>(
            new SleMatrixBuilderPort(
                *meshInfoManager_.getMeshInfoP(),
                solverDataStores_.getSavedCoeffsStoreP(),
                solverDataStores_.getSavedRhsStoreP())));
}

}