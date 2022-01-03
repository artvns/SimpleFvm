#include "CoeffsPressPorts.h"

namespace fvmsolver {

CoeffsPressPorts::CoeffsPressPorts(
                    DataManager& dataManager,
                    SolverDataStoresCreator& solverDataManager) :
                            dataManager_(dataManager),
                            solverDataManager_(solverDataManager) {

}

std::unique_ptr<CoeffsPressPort> CoeffsPressPorts::createPortP(std::string name) {
    return std::move(
        std::unique_ptr<CoeffsPressPort>(
            new CoeffsPressPort(
                dataManager_.getFluidProperties(), 
        dataManager_.getMeshParametersP(),
        dataManager_.getCellNumsGlobalP(name),
        dataManager_.getAdjCellInterNumsP(name),
        solverDataManager_.getCoeffsCalculatorsStore())));
}

}