#include "NumsPackerU.h"

namespace meshloader {

NumsPackerU::NumsPackerU(DataStoreMasks& dataStoreMasks,
                         Mesh& mesh,
                         NumsSets& numsSets) :
                                    AbstractNumsPacker(dataStoreMasks, 
                                                       mesh, 
                                                       numsSets) {

}

void NumsPackerU::createStores(std::string partName, size_t partSize) {
    dataStoreMasks_.getCellInterNumsUMask(partName).createStore(partSize);
    dataStoreMasks_.getCellNumsGlobalUMask(partName).createStore(partSize);
    dataStoreMasks_.getAdjCellGlobalNumsUMask(partName).createStore(partSize);
    dataStoreMasks_.getAdjCellInterNumsUMask(partName).createStore(partSize);
}

void NumsPackerU::packPart(std::string partName, size_t partSize) {
    packCellInteriorNum(
        partName, 
        partSize, 
        dataStoreMasks_.getCellInterNumsUMask(partName)
    );

    packAdjCellInteriorNum(
        partName, 
        partSize, 
        dataStoreMasks_.getAdjCellInterNumsUMask(partName)
    );

    packCellGlobalNum(
        partName, 
        partSize, 
        dataStoreMasks_.getCellNumsGlobalUMask(partName)
    );

    packAdjCellGlobalNum(
        partName, 
        partSize, 
        dataStoreMasks_.getAdjCellGlobalNumsUMask(partName)
    );
}

void NumsPackerU::packCellInteriorNum(std::string partName, 
                    size_t partSize, CellNumsInteriorMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.setCellNumP(idx, 
                    mesh_.getCell(num)->getCellU().getInteriorNum());

        dataMask.setCellNumW(idx, 
                    mesh_.getAdjCellW(num)->getCellU().getInteriorNum());

        dataMask.setCellNumE(idx, 
                    mesh_.getAdjCellE(num)->getCellU().getInteriorNum());

        dataMask.setCellNumN(idx, 
                    mesh_.getAdjCellN(num)->getCellU().getInteriorNum());

        dataMask.setCellNumS(idx, 
                    mesh_.getAdjCellS(num)->getCellU().getInteriorNum());
    }
}

void NumsPackerU::packCellGlobalNum(std::string partName, 
                        size_t partSize, CellNumsGlobalMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.set_pCellNum(idx, 
                    mesh_.getCell(num)->getCellU().getGlobalNum());

        dataMask.set_wCellNum(idx, 
                    mesh_.getAdjCellW(num)->getCellU().getGlobalNum());

        dataMask.set_eCellNum(idx, 
                    mesh_.getAdjCellE(num)->getCellU().getGlobalNum());

        dataMask.set_nCellNum(idx, 
                    mesh_.getAdjCellN(num)->getCellU().getGlobalNum());

        dataMask.set_sCellNum(idx, 
                    mesh_.getAdjCellS(num)->getCellU().getGlobalNum());
    }
}

void NumsPackerU::packAdjCellGlobalNum(std::string partName, 
                    size_t partSize, AdjCellGlobalNumsUMask& dataMask) {
             
    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);


        dataMask.setNumPp(idx, 
                    mesh_.getCell(num)->getCellP().getGlobalNum());

        dataMask.setNumPw(idx, 
                    mesh_.getAdjCellW(num)->getCellP().getGlobalNum());


        dataMask.setNumUe(idx, 
                    mesh_.getAdjCellE(num)->getCellU().getGlobalNum());

        dataMask.setNumUw(idx, 
                    mesh_.getAdjCellW(num)->getCellU().getGlobalNum());

        dataMask.setNumVne(idx, 
                    mesh_.getCell(num)->getMacroCellN()->getCellV().getGlobalNum());
    
        dataMask.setNumVnw(idx, 
                    mesh_.getAdjCellN(mesh_.getAdjCellW(num)->
                        getCellGlobalNum())->getCellV().getGlobalNum());

        dataMask.setNumVse(idx, 
                    mesh_.getCell(num)->getCellV().getGlobalNum());
    
        dataMask.setNumVsw(idx, 
                    mesh_.getAdjCellW(num)->getCellV().getGlobalNum());
    }
}

void NumsPackerU::packAdjCellInteriorNum(std::string partName, 
                    size_t partSize, AdjCellInteriorNumsUMask& dataMask) {

    for (size_t idx = 0; idx < partSize; idx++) {
        size_t num = numsSets_.getNumsSet(partName[0]).at(idx);

        dataMask.set_numPp(idx, 
                    mesh_.getCell(num)->getCellP().getInteriorNum());

        dataMask.set_numPw(idx, 
                    mesh_.getAdjCellW(num)->getCellP().getInteriorNum());
    }
}

}