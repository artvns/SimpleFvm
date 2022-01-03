#include "CoeffsPartsCommonCreator.h"

namespace fvmsolver {

CoeffsPartsCommonCreator::CoeffsPartsCommonCreator(
                DataManager& dataManager, 
                MeshInfoManager& meshInfoManager,
                SolverDataStoresCreator& solverDataStores) :
                        cellNumsSets_(dataManager, meshInfoManager),
                        cellTypesSets_(dataManager, meshInfoManager),
                        dataExchangerSets_ (dataManager, meshInfoManager,
                                                         solverDataStores) {

}

CoeffsPartsCommonCreator::shPtrMapCellNumbers CoeffsPartsCommonCreator::getCellNumbersSetU() {
    return cellNumsSets_.createSetForU();
}

CoeffsPartsCommonCreator::shPtrMapCellNumbers CoeffsPartsCommonCreator::getCellNumbersSetV() {
    return cellNumsSets_.createSetForV();
}

CoeffsPartsCommonCreator::shPtrMapCellNumbers CoeffsPartsCommonCreator::getCellNumbersSetP() {
    return cellNumsSets_.createSetForP();
}

CoeffsPartsCommonCreator::shPtrMapCellTypes CoeffsPartsCommonCreator::getCellTypesSetU() {
    return cellTypesSets_.createSetForU();
}

CoeffsPartsCommonCreator::shPtrMapCellTypes CoeffsPartsCommonCreator::getCellTypesSetV() {
    return cellTypesSets_.createSetForV();
}

CoeffsPartsCommonCreator::shPtrMapCellTypes CoeffsPartsCommonCreator::getCellTypesSetP() {
    return cellTypesSets_.createSetForP();
}

CoeffsPartsCommonCreator::shPtrMapAbstDataExchanger CoeffsPartsCommonCreator::getDataExchangerSetU() {
    return dataExchangerSets_.createSetForU();
}

CoeffsPartsCommonCreator::shPtrMapAbstDataExchanger CoeffsPartsCommonCreator::getDataExchangerSetV() {
    return dataExchangerSets_.createSetForV();
}

CoeffsPartsCommonCreator::shPtrMapAbstDataExchanger CoeffsPartsCommonCreator::getDataExchangerSetP() {
    return dataExchangerSets_.createSetForP();
}

}