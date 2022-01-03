#include "CoeffsPartsPressureCreator.h"

namespace fvmsolver {

CoeffsPartsPressureCreator::CoeffsPartsPressureCreator(
    DataManager& dataManager, 
    MeshInfoManager& meshInfoManager,
    MathToolsManager& mathToolsManager,
    SolverDataStoresCreator& solverDataManager) :
        coeffsPressSets_(dataManager, solverDataManager, meshInfoManager),
        rhsPressSets_(dataManager, mathToolsManager, meshInfoManager) {

}

CoeffsPartsPressureCreator::shPtrMapCoeffsPress CoeffsPartsPressureCreator::getCoeffsPressSet() {
    return coeffsPressSets_.createSet();
}

CoeffsPartsPressureCreator::shPtrMapRhsPress CoeffsPartsPressureCreator::getRhsPressSet() {
    return rhsPressSets_.createSet();
}

}