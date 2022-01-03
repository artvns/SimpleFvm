#include "DataExchangerSets.h"

namespace fvmsolver {

DataExchangerSets::DataExchangerSets(
                DataManager& dataManager,
                MeshInfoManager& meshInfoManager,
                SolverDataStoresCreator& solverDataStores) :
                        dataPorts_(dataManager, solverDataStores), 
                        setsMakerU_(meshInfoManager),
                        setsMakerV_(meshInfoManager),
                        setsMakerP_(meshInfoManager) {

}

DataExchangerSets::shPtrMapAbstDataExchanger DataExchangerSets::createSetForU() {
    return setsMakerU_.createSetForU(dataPorts_);
}

DataExchangerSets::shPtrMapAbstDataExchanger DataExchangerSets::createSetForV() {
    return setsMakerV_.createSetForV(dataPorts_);
}

DataExchangerSets::shPtrMapAbstDataExchanger DataExchangerSets::createSetForP() {
    return setsMakerP_.createSetForP(dataPorts_);
}

}