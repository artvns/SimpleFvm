#include "NumsSetsCreatorV.h"

namespace meshloader {

NumsSetsCreatorV::NumsSetsCreatorV(  
                    Mesh& mesh, 
                    NumsSets& numsSetsP, 
                    NumsSets& numsSetsVel) :
                            AbstractNumsSetsCreator(mesh, 
                                                    numsSetsP, 
                                                    numsSetsVel) {

}

void NumsSetsCreatorV::createInteriorSet(char setName) {

    size_t setSize = numsSetsP_.getNumsSet(setName).size();
    for (size_t i = 0; i < setSize; i++) {

        size_t globNum = numsSetsP_.getNumsSet(setName).at(i);

        if (!isGhostCellS(globNum) && !isGhostCellN(globNum)) {
            numsSet_.push_back(globNum);
        }
        if (isGhostCellN_N(globNum)) {
            numsSet_.push_back(
                mesh_.getCell(globNum)->getMacroCellN()->getCellGlobalNum());
        }
        
    }
    numsSetsVel_.addNumsSet(setName, numsSet_);
    numsSet_.clear();
}

void NumsSetsCreatorV::createFacesSets(char setName) {

    size_t setSize = numsSetsP_.getNumsSet(setName).size();
    for (size_t i = 0; i < setSize; i++) {
        size_t globNum = numsSetsP_.getNumsSet(setName).at(i);
        if (!isGhostCellS(globNum) && !isGhostCellN(globNum)) {
            numsSet_.push_back(globNum);
        }
        if (!isGhostCellS(globNum) && !isGhostCellN(globNum) && isGhostCellN_N(globNum)){
            numsSet_.push_back(
                mesh_.getCell(globNum)->getMacroCellN()->getCellGlobalNum());
        }
    }
    if (numsSet_.size() > 0) {
        numsSetsVel_.addNumsSet(setName, numsSet_);
    }
    numsSet_.clear();
}

bool NumsSetsCreatorV::isGhostCellN_N(size_t globNum) {
    // Checking if the cell next to N after the current N is the GHOST type cell.
    return mesh_.getCell(globNum)->getMacroCellN()->
                                   getMacroCellN()->
                                   isGhostCell();
}

}