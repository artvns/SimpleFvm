#include "CellNumsSets.h"

namespace fvmsolver {

CellNumsSets::CellNumsSets(
                DataManager& dataManager,
                MeshInfoManager& meshInfoManager) : 
                                dataPorts_(dataManager),
                                setsMaker_(meshInfoManager) {

}

CellNumsSets::shPtrMapCellNumbers CellNumsSets::createSetForU() {
    return setsMaker_.createSetForU(dataPorts_);
}

CellNumsSets::shPtrMapCellNumbers CellNumsSets::createSetForV() {
    return setsMaker_.createSetForV(dataPorts_);
}

CellNumsSets::shPtrMapCellNumbers CellNumsSets::createSetForP() {
    return setsMaker_.createSetForP(dataPorts_);
}

}