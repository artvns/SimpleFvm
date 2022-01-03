#include "ResidsCalculatorSets.h"

namespace fvmsolver {

ResidsCalculatorSets::ResidsCalculatorSets(
                DataManager& dataManager, 
                MeshInfoManager& meshInfoManager,
                MathToolsManager& mathToolsManager,
                SolverDataStoresCreator& solverDataManager) : 
                        dataPorts_(dataManager, 
                                   mathToolsManager, 
                                   meshInfoManager,
                                   solverDataManager),
                        setsMakerU_(meshInfoManager),
                        setsMakerV_(meshInfoManager),
                        setsMakerP_(meshInfoManager) {

}

ResidsCalculatorSets::shPtrMapIResidsCalculator ResidsCalculatorSets::createSetU() {
    return setsMakerU_.createSetForU(dataPorts_);
}

ResidsCalculatorSets::shPtrMapIResidsCalculator ResidsCalculatorSets::createSetV() {
    return setsMakerV_.createSetForV(dataPorts_);
}

ResidsCalculatorSets::shPtrMapIResidsCalculator ResidsCalculatorSets::createSetP() {
    return setsMakerP_.createSetForP(dataPorts_);
}

}