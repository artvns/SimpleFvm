#include "CellTypesSets.h"

namespace fvmsolver {

CellTypesSets::CellTypesSets(
                DataManager& dataManager,
                MeshInfoManager& meshInfoManager) :
                                dataPorts_(dataManager), 
                                setsMaker_(meshInfoManager) {

}

CellTypesSets::shPtrMapCellTypes CellTypesSets::createSetForU() {
    return setsMaker_.createSetForU(dataPorts_);
}

CellTypesSets::shPtrMapCellTypes CellTypesSets::createSetForV() {
    return setsMaker_.createSetForV(dataPorts_);
}

CellTypesSets::shPtrMapCellTypes CellTypesSets::createSetForP() {
    return setsMaker_.createSetForP(dataPorts_);
}

}