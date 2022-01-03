#include "NumsSetsCreatorU.h"

namespace meshloader {

NumsSetsCreatorU::NumsSetsCreatorU(
                    Mesh& mesh, 
                    NumsSets& numsSetsP, 
                    NumsSets& numsSetsVel) :
                            AbstractNumsSetsCreator(mesh, 
                                                    numsSetsP, 
                                                    numsSetsVel) {

}

void NumsSetsCreatorU::createInteriorSet(char setName) {

    size_t setSize = numsSetsP_.getNumsSet(setName).size();
    for (size_t i = 0; i < setSize; i++) {

        size_t globNum = numsSetsP_.getNumsSet(setName).at(i);

        if (!isGhostCellW(globNum) && !isGhostCellE(globNum)) {
            numsSet_.push_back(globNum);
        }
        if (isGhostCellE_E(globNum)) {
            numsSet_.push_back(
                mesh_.getCell(globNum)->getMacroCellE()->getCellGlobalNum());
        }
        
    }
    numsSetsVel_.addNumsSet(setName, numsSet_);
    numsSet_.clear();
}

void NumsSetsCreatorU::createFacesSets(char setName) {

    size_t setSize = numsSetsP_.getNumsSet(setName).size();
    for (size_t i = 0; i < setSize; i++) {
        size_t globNum = numsSetsP_.getNumsSet(setName).at(i);
        if (!isGhostCellW(globNum) && !isGhostCellE(globNum)) {
            numsSet_.push_back(globNum);
        }
        if (!isGhostCellW(globNum) && !isGhostCellE(globNum) && isGhostCellE_E(globNum)){
            numsSet_.push_back(
                mesh_.getCell(globNum)->getMacroCellE()->getCellGlobalNum());
        }
    }
    if (numsSet_.size() > 0) {
        numsSetsVel_.addNumsSet(setName, numsSet_);
    }
    numsSet_.clear();
}

bool NumsSetsCreatorU::isGhostCellE_E(size_t globNum) {
    // Checking if the cell next to E after the current E is the GHOST type cell.
    return mesh_.getCell(globNum)->getMacroCellE()->
                                   getMacroCellE()->
                                   isGhostCell();
}

}