#include "VerticalFaceNums.h"

namespace meshloader {

VerticalFaceNums::VerticalFaceNums(
        BaseMatrix& baseMatrix,
        BaseMatrix& templateMatrixP,
        NumsMatrix& interiorNumsMatrixP,
        std::vector<std::vector<size_t>>& numsSets) :
                        baseMatrix_(baseMatrix),
                        templateMatrixP_(templateMatrixP),
                        interiorNumsMatrixP_(interiorNumsMatrixP),
                        allNums_(numsSets) {

}

void VerticalFaceNums::findNums() {
    size_t maxLines_ = baseMatrix_.getRowsAmount();
    size_t maxColumns_ = baseMatrix_.getColsAmount();

    for (size_t j = 0; j < maxColumns_; j++) {
        checkLeftSide(j, maxLines_);
        checkRightSide(j, maxLines_);
    }

    uniteLeftRightSets();
}

void VerticalFaceNums::checkLeftSide(size_t j, size_t maxLines) {

    for (size_t i = 0; i < maxLines; i++) {
        if (isCell(i, j) & !isHorizFaceNum(i, j) && isLeftSide(i, j)) {
            oneLeftFaceNums_.push_back(takeNumber(i, j));
            if (isLeftFaceFinish(i, j)) {
                allLeftNums_.push_back(oneLeftFaceNums_);
                oneLeftFaceNums_.clear();
            }
        }
    }
}

void VerticalFaceNums::checkRightSide(size_t j, size_t maxLines) {

    for (size_t i = 0; i < maxLines; i++) {
        if (isCell(i, j) & !isHorizFaceNum(i, j) && isRightSide(i, j)) {
            oneRightFaceNums_.push_back(takeNumber(i, j));
            if (isRightFaceFinish(i, j)) {
                allRightNums_.push_back(oneRightFaceNums_);
                oneRightFaceNums_.clear();
            }
        }
    }
}

size_t VerticalFaceNums::takeNumber(size_t i, size_t j) {
    i++;
    j++;

    return interiorNumsMatrixP_.getValue(i, j);
}

bool VerticalFaceNums::isCell(size_t i, size_t j) {
    if ('0' != baseMatrix_.getValue(i, j)) {
        return true;
    }
    else {
        return false;
    }
}

bool VerticalFaceNums::isLeftSide(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i, j - 1)) {
        return true;
    }
    else {
        return false;
    }
}

bool VerticalFaceNums::isRightSide(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i, j + 1)) {
        return true;
    }
    else {
        return false;
    }
}

bool VerticalFaceNums::isLeftFaceFinish(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i + 2, j )) {
        return true;
    }
    else if ('0' != templateMatrixP_.getValue(i + 1, j - 1)) {
        return true;
    }
    else {
        return false;
    }
}

bool VerticalFaceNums::isRightFaceFinish(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i + 2, j)) {
        return true;
    }
    else if ('0' != templateMatrixP_.getValue(i + 1, j + 1)) {
        return true;
    }
    else {
        return false;
    }
}

void VerticalFaceNums::uniteLeftRightSets() {

    for (size_t i = 0; i < allLeftNums_.size(); i++) {
        allNums_.push_back(allLeftNums_.at(i));
    }
    for (size_t i = 0; i < allRightNums_.size(); i++) {
        allNums_.push_back(allRightNums_.at(i));
    }
}

bool VerticalFaceNums::isHorizFaceNum(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i - 1, j)) {
        return true;
    }
    else if ('0' == templateMatrixP_.getValue(i + 1, j)) {
        return true;
    }
    else {
        return false;   
    }
}

}