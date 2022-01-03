#include "CoeffsPressSets.h"

namespace fvmsolver {

CoeffsPressSets::CoeffsPressSets(
                DataManager& dataManager,
                SolverDataStoresCreator& solverDataManager,
                MeshInfoManager& meshInfoManager) : 
                        dataPorts_(dataManager, solverDataManager),
                        setsMaker_(meshInfoManager) {

}

CoeffsPressSets::shPtrMapCoeffsPress CoeffsPressSets::createSet() {
    return setsMaker_.createSetForP(dataPorts_);
}

}