#include "PureInteriorNums.h"

namespace meshloader {

PureInteriorNums::PureInteriorNums(
            BaseMatrix& baseMatrix,
            BaseMatrix& templateMatrixP,
            NumsMatrix& interiorNumsMatrixP) :
                            baseMatrix_(baseMatrix),
                            templateMatrixP_(templateMatrixP),
                            interiorNumsMatrixP_(interiorNumsMatrixP) {

}

void PureInteriorNums::findNums(std::vector<size_t>& interiorNumsSet,
                const std::vector<std::vector<size_t>>& facesNumsSets) {

    uniteFacesNums(facesNumsSets);

    sortVector(facesNums_);
    removeDuplicatedValues(facesNums_);

    size_t maxLines_ = baseMatrix_.getRowsAmount();
    size_t maxColumns_ = baseMatrix_.getColsAmount();

    for (size_t i = 0; i < maxLines_; i++) {
        for (size_t j = 0; j < maxColumns_; j++) {
            if (isCell(i, j) & !isFaceNum(takeNumber(i, j))) {
                interiorNumsSet.push_back(takeNumber(i, j));
            }
        }
    }

    sortVector(interiorNumsSet);
}

size_t PureInteriorNums::takeNumber(size_t i, size_t j) {
    return interiorNumsMatrixP_.getValue(++i, ++j);
}

bool PureInteriorNums::isCell(size_t i, size_t j) {
    if ('0' != baseMatrix_.getValue(i, j)) {
        return true;
    }
    else {
        return false;
    }
}

bool PureInteriorNums::isFaceNum(const size_t num) {
    if (std::binary_search(facesNums_.begin(), facesNums_.end(), num)) {
        return true;
    }
    else {
        return false;
    }
}

void PureInteriorNums::uniteFacesNums(const std::vector<std::vector<size_t>>& nums) {
    for (size_t i = 0; i < nums.size(); i++) {
        for (size_t j = 0; j < nums.at(i).size(); j++) {
            facesNums_.push_back(nums.at(i).at(j));
        }
    }
}

void PureInteriorNums::sortVector(std::vector<size_t>& v) {
    std::sort(v.begin(), v.end());
}

void PureInteriorNums::removeDuplicatedValues(std::vector<size_t>& v) {
    v.erase(std::unique(v.begin(), v.end()), v.end());
}

}