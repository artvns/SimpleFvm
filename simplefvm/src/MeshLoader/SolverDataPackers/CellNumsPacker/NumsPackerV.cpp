#include "NumsPackerV.h"

namespace meshloader {

NumsPackerV::NumsPackerV(DataStoreMasks& dataStoreMasks,
                         Mesh& mesh,
                         NumsSets& numsSets) :
                                    AbstractNumsPacker(dataStoreMasks, 
                                                       mesh, 
                                                       numsSets) {

}

void NumsPackerV::createStores(std::string partName, size_t partSize) {
    dataStoreMasks_.getCellInterNumsVMask(partName).createStore(partSize);
    dataStoreMasks_.getCellNumsGlobalVMask(partName).createStore(partSize);
    dataStoreMasks_.getAdjCellGlobalNumsVMask(partName).createStore(partSize);
    dataStoreMasks_.getAdjCellInterNumsVMask(partName).createStore(partSize);
}

void NumsPackerV::packPart(std::string partName, size_t partSize) {
    packCellInteriorNum(
        partName, 
        partSize, 
        dataStoreMasks_.getCellInterNumsVMask(partName)
    );

    packAdjCellInteriorNum(
        partName, 
        partSize, 
        dataStoreMasks_.getAdjCellInterNumsVMask(partName)
    );

    packCellGlobalNum(
        partName, 
        partSize, 
        dataStoreMasks_.getCellNumsGlobalVMask(partName)
    );

    packAdjCellGlobalNum(
        partName, 
        partSize, 
        dataStoreMasks_.getAdjCellGlobalNumsVMask(partName)
    );
}

void NumsPackerV::packCellInteriorNum(std::string partName, 
                    size_t partSize, CellNumsInteriorMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.setCellNumP(idx, 
                    mesh_.getCell(num)->getCellV().getInteriorNum());

        dataMask.setCellNumW(idx, 
                    mesh_.getAdjCellW(num)->getCellV().getInteriorNum());

        dataMask.setCellNumE(idx, 
                    mesh_.getAdjCellE(num)->getCellV().getInteriorNum());

        dataMask.setCellNumN(idx, 
                    mesh_.getAdjCellN(num)->getCellV().getInteriorNum());

        dataMask.setCellNumS(idx, 
                    mesh_.getAdjCellS(num)->getCellV().getInteriorNum());
    }
}

void NumsPackerV::packCellGlobalNum(std::string partName, 
                        size_t partSize, CellNumsGlobalMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.set_pCellNum(idx, 
                    mesh_.getCell(num)->getCellV().getGlobalNum());

        dataMask.set_wCellNum(idx, 
                    mesh_.getAdjCellW(num)->getCellV().getGlobalNum());

        dataMask.set_eCellNum(idx, 
                    mesh_.getAdjCellE(num)->getCellV().getGlobalNum());

        dataMask.set_nCellNum(idx, 
                    mesh_.getAdjCellN(num)->getCellV().getGlobalNum());

        dataMask.set_sCellNum(idx, 
                    mesh_.getAdjCellS(num)->getCellV().getGlobalNum());
    }
}

void NumsPackerV::packAdjCellGlobalNum(std::string partName, 
                    size_t partSize, AdjCellGlobalNumsVMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.setNumPp(idx, 
                    mesh_.getCell(num)->getCellP().getGlobalNum());

        dataMask.setNumPs(idx, 
                    mesh_.getAdjCellS(num)->getCellP().getGlobalNum());


        dataMask.setNumVn(idx, 
                    mesh_.getAdjCellN(num)->getCellV().getGlobalNum());

        dataMask.setNumVs(idx, 
                    mesh_.getAdjCellS(num)->getCellV().getGlobalNum());


        dataMask.setNumUen(idx, 
                    mesh_.getAdjCellE(num)->getCellU().getGlobalNum());

        dataMask.setNumUes(idx, 
                    mesh_.getAdjCellE(mesh_.getAdjCellS(num)->
                        getCellGlobalNum())->getCellU().getGlobalNum());

        dataMask.setNumUwn(idx, 
                    mesh_.getCell(num)->getCellU().getGlobalNum());

        dataMask.setNumUws(idx, 
                    mesh_.getAdjCellS(num)->getCellU().getGlobalNum());
    }
}

void NumsPackerV::packAdjCellInteriorNum(std::string partName, 
                    size_t partSize, AdjCellInteriorNumsVMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.set_numPp(idx, 
                    mesh_.getCell(num)->getCellP().getInteriorNum());

        dataMask.set_numPs(idx, 
                    mesh_.getAdjCellS(num)->getCellP().getInteriorNum());
    }
}

}