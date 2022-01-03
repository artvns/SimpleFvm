#include "CellTypesPacker.h"

namespace meshloader {

CellTypesPacker::CellTypesPacker(
                                DataStoreMasks& dataContainer, 
                                Mesh& mesh) :
                                            dataContainer_(dataContainer),
                                            mesh_(mesh) {

}

void CellTypesPacker::packCellTypes() {
    size_t allCellsAmount_ = mesh_.getCellsAmount();

    createStores(allCellsAmount_);

    // First set GHOST type value to all.
    for (size_t i = 0; i < allCellsAmount_; i++) {
        size_t num_ = mesh_.getCellByIndex(i)->getCellGlobalNum();
        setGhostTypes(num_);
    }

     // Then set other types.
    for (size_t i = 0; i < allCellsAmount_; i++) {
        size_t num_ = mesh_.getCellByIndex(i)->getCellGlobalNum();
        packCellTypesP(num_);
        packCellTypesU(num_);
        packCellTypesV(num_);
    }
}

void CellTypesPacker::setGhostTypes(size_t cellNum) {
    size_t numAsIndex_ = cellNum - 1;

    dataContainer_.getAdjCellTypesMaskP().setCellTypeAsBcGhost(numAsIndex_);
    dataContainer_.getAdjCellTypesMaskU().setCellTypeAsBcGhost(numAsIndex_);
    dataContainer_.getAdjCellTypesMaskV().setCellTypeAsBcGhost(numAsIndex_);
}

void CellTypesPacker::packCellTypesP(size_t cellNum) {
    size_t numAsIndex_ = cellNum - 1;

    if (!mesh_.getCell(cellNum)->isGhostCell()) {
        dataContainer_.getAdjCellTypesMaskP().setCellTypeAsInterior(numAsIndex_);
    }
}

void CellTypesPacker::packCellTypesU(size_t cellNum) {
    size_t numAsIndex_ = cellNum - 1;

    if (!mesh_.getCell(cellNum)->isGhostCell()) {
        if (mesh_.getAdjCellW(cellNum)->isGhostCell()) {
            dataContainer_.getAdjCellTypesMaskU().setCellTypeAsBcReal(numAsIndex_);
        }
        else if (!mesh_.getAdjCellW(cellNum)->isGhostCell()) {
            dataContainer_.getAdjCellTypesMaskU().setCellTypeAsInterior(numAsIndex_);
        }
        if (mesh_.getAdjCellE(cellNum)->isGhostCell()) {
            numAsIndex_ = mesh_.getAdjCellE(cellNum)->getCellGlobalNum() - 1;
            dataContainer_.getAdjCellTypesMaskU().setCellTypeAsBcReal(numAsIndex_);
        }
    }
}

void CellTypesPacker::packCellTypesV(size_t cellNum) {
    size_t numAsIndex_ = cellNum - 1;

    if (!mesh_.getCell(cellNum)->isGhostCell()) {
        if (mesh_.getAdjCellS(cellNum)->isGhostCell()) {
            dataContainer_.getAdjCellTypesMaskV().setCellTypeAsBcReal(numAsIndex_);
        }
        else if (!mesh_.getAdjCellS(cellNum)->isGhostCell()) {
            dataContainer_.getAdjCellTypesMaskV().setCellTypeAsInterior(numAsIndex_);
        }
        if (mesh_.getAdjCellN(cellNum)->isGhostCell()) {
            numAsIndex_ = mesh_.getAdjCellN(cellNum)->getCellGlobalNum() - 1;
            dataContainer_.getAdjCellTypesMaskV().setCellTypeAsBcReal(numAsIndex_);
        }
    }
}

void CellTypesPacker::createStores(size_t storeSize) {
    dataContainer_.getAdjCellTypesMaskP().createStore(storeSize);
    dataContainer_.getAdjCellTypesMaskU().createStore(storeSize);
    dataContainer_.getAdjCellTypesMaskV().createStore(storeSize);
}

}