#include "NumsPackerP.h"

namespace meshloader {

NumsPackerP::NumsPackerP(DataStoreMasks& dataStoreMasks,
                         Mesh& mesh,
                         NumsSets& numsSets) :
                                    AbstractNumsPacker(dataStoreMasks, 
                                                       mesh, 
                                                       numsSets) {

}

void NumsPackerP::createStores(std::string partName, size_t partSize) {
    dataStoreMasks_.getCellInterNumsPMask(partName).createStore(partSize);
    dataStoreMasks_.getCellNumsGlobalPMask(partName).createStore(partSize);
    dataStoreMasks_.getAdjCellGlobalNumsPMask(partName).createStore(partSize);
    dataStoreMasks_.getAdjCellInterNumsPMask(partName).createStore(partSize);
}

void NumsPackerP::packPart(std::string partName, size_t partSize) {
    packCellInteriorNum(
        partName, 
        partSize, 
        dataStoreMasks_.getCellInterNumsPMask(partName)
    );

    packAdjCellInteriorNum(
        partName, 
        partSize, 
        dataStoreMasks_.getAdjCellInterNumsPMask(partName)
    );

    packCellGlobalNum(
        partName, 
        partSize, 
        dataStoreMasks_.getCellNumsGlobalPMask(partName)
    );

    packAdjCellGlobalNum(
        partName, 
        partSize, 
        dataStoreMasks_.getAdjCellGlobalNumsPMask(partName)
    );
}

void NumsPackerP::packCellInteriorNum(std::string partName, 
                    size_t partSize, CellNumsInteriorMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.setCellNumP(idx, 
                    mesh_.getCell(num)->getCellP().getInteriorNum());

        dataMask.setCellNumW(idx, 
                    mesh_.getAdjCellW(num)->getCellP().getInteriorNum());

        dataMask.setCellNumE(idx, 
                    mesh_.getAdjCellE(num)->getCellP().getInteriorNum());

        dataMask.setCellNumN(idx, 
                    mesh_.getAdjCellN(num)->getCellP().getInteriorNum());

        dataMask.setCellNumS(idx, 
                    mesh_.getAdjCellS(num)->getCellP().getInteriorNum());
    }
}

void NumsPackerP::packCellGlobalNum(std::string partName, 
                    size_t partSize, CellNumsGlobalMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.set_pCellNum(idx, 
                    mesh_.getCell(num)->getCellP().getGlobalNum());

        dataMask.set_wCellNum(idx, 
                    mesh_.getAdjCellW(num)->getCellP().getGlobalNum());

        dataMask.set_eCellNum(idx, 
                    mesh_.getAdjCellE(num)->getCellP().getGlobalNum());

        dataMask.set_nCellNum(idx, 
                    mesh_.getAdjCellN(num)->getCellP().getGlobalNum());

        dataMask.set_sCellNum(idx, 
                    mesh_.getAdjCellS(num)->getCellP().getGlobalNum());
    }
}

void NumsPackerP::packAdjCellGlobalNum(std::string partName, 
                    size_t partSize, AdjCellGlobalNumsPMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.set_numUStarW(idx, 
                    mesh_.getCell(num)->getCellU().getGlobalNum());

        dataMask.set_numUStarE(idx, 
                    mesh_.getAdjCellE(num)->getCellU().getGlobalNum());


        dataMask.set_numVStarS(idx, 
                    mesh_.getCell(num)->getCellV().getGlobalNum());

        dataMask.set_numVStarN(idx, 
                    mesh_.getAdjCellN(num)->getCellV().getGlobalNum());
    }
}

void NumsPackerP::packAdjCellInteriorNum(std::string partName, 
                    size_t partSize, AdjCellInteriorNumsPMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.set_numUStarW(idx, 
                    mesh_.getCell(num)->getCellU().getInteriorNum());

        dataMask.set_numUStarE(idx, 
                    mesh_.getAdjCellE(num)->getCellU().getInteriorNum());


        dataMask.set_numVStarS(idx, 
                    mesh_.getCell(num)->getCellV().getInteriorNum());

        dataMask.set_numVStarN(idx, 
                    mesh_.getAdjCellN(num)->getCellV().getInteriorNum());
    }
}

}