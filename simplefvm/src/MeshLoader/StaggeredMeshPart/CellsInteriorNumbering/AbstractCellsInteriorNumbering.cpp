#include "AbstractCellsInteriorNumbering.h"

namespace meshloader {

AbstractCellsInteriorNumbering::AbstractCellsInteriorNumbering(
                        Mesh& mesh,
                        NumsSets& numsSets) :
                                mesh_(mesh),
                                numsSets_(numsSets) {

}

AbstractCellsInteriorNumbering::~AbstractCellsInteriorNumbering() {

}

void AbstractCellsInteriorNumbering::numberCells() {
    combineNums();
    sortVector(globNums_);
    removeDuplicatedValues(globNums_);

    size_t interiorNum_ = 0;

    for (size_t i = 0; i < globNums_.size(); i++) {
        size_t globalNum = globNums_.at(i);

        if (!mesh_.getCell(globalNum)->isGhostCell()) {
            interiorNum_++;
            setInteriorNum(globalNum, interiorNum_);
        }
    }
}

void AbstractCellsInteriorNumbering::combineNums() {
    for (size_t numSet = 0; numSet < numsSets_.getSetsAmount(); numSet++) {

        char   setName = numsSets_.getPartNamesSet().at(numSet);
        size_t setSize = numsSets_.getNumsSet(setName).size();

        for (size_t j = 0; j < setSize; j++) {
            globNums_.push_back(numsSets_.getNumsSet(setName).at(j));
        }
    }
}

void AbstractCellsInteriorNumbering::sortVector(std::vector<size_t>& v) {
    std::sort(v.begin(), v.end());
}

void AbstractCellsInteriorNumbering::removeDuplicatedValues(std::vector<size_t>& v) {
    v.erase(std::unique(v.begin(), v.end()), v.end());
}

}