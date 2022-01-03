#include "HorizontalFaceNums.h"

namespace meshloader {

HorizontalFaceNums::HorizontalFaceNums(
            BaseMatrix& baseMatrix,
            BaseMatrix& templateMatrixP,
            NumsMatrix& interiorNumsMatrixP,
            std::vector<std::vector<size_t>>& numsSets) :
                            baseMatrix_(baseMatrix),
                            templateMatrixP_(templateMatrixP),
                            interiorNumsMatrixP_(interiorNumsMatrixP),
                            allNums_(numsSets) {

}

void HorizontalFaceNums::findNums() {
    size_t maxLines_ = baseMatrix_.getRowsAmount();
    size_t maxColumns_ = baseMatrix_.getColsAmount();

    for (size_t i = 0; i < maxLines_; i++) {
        checkTopSide(i, maxColumns_);
        checkBottomSide(i, maxColumns_);
    }

    uniteTopBottomSets();
}

void HorizontalFaceNums::checkTopSide(size_t i, size_t maxCols) {
    for (size_t j = 0; j < maxCols; j++) {
        if (isCell(i, j) && isTopSide(i, j)) {
            oneTopFaceNums_.push_back(takeNumber(i, j));
            if (isTopFaceFinish(i, j)) {
                allTopNums_.push_back(oneTopFaceNums_);
                oneTopFaceNums_.clear();
            }
        }
    }
}

void HorizontalFaceNums::checkBottomSide(size_t i, size_t maxCols) {
    for (size_t j = 0; j < maxCols; j++) {
        if (isCell(i, j) && isBottomSide(i, j)) {
            oneBottomFaceNums_.push_back(takeNumber(i, j));
            if (isBottomFaceFinish(i, j)) {
                allBottomNums_.push_back(oneBottomFaceNums_);
                oneBottomFaceNums_.clear();
            }
        }
    }
}

size_t HorizontalFaceNums::takeNumber(size_t i, size_t j) {
    return interiorNumsMatrixP_.getValue(++i, ++j);
}

bool HorizontalFaceNums::isCell(size_t i, size_t j) {
    if ('0' != baseMatrix_.getValue(i, j)) {
        return true;
    }
    else {
        return false;
    }
}

bool HorizontalFaceNums::isTopSide(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i - 1, j)) {
        return true;
    }
    else {
        return false;
    }
}

bool HorizontalFaceNums::isBottomSide(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i + 1, j)) {
        return true;
    }
    else {
        return false;
    }
}

bool HorizontalFaceNums::isTopFaceFinish(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i, j + 1)) {
        return true;
    }
    else if ('0' != templateMatrixP_.getValue(i - 1, j + 1)) {
        return true;
    }
    else {
        return false;
    }
}

bool HorizontalFaceNums::isBottomFaceFinish(size_t i, size_t j) {
    i++;
    j++;

    if ('0' == templateMatrixP_.getValue(i, j + 1)) {
        return true;
    }
    else if ('0' != templateMatrixP_.getValue(i + 1, j + 1)) {
        return true;
    }
    else {
        return false;
    }
}

void HorizontalFaceNums::uniteTopBottomSets() {

    for (size_t i = 0; i < allTopNums_.size(); i++) {
        allNums_.push_back(allTopNums_.at(i));
    }
    for (size_t i = 0; i < allBottomNums_.size(); i++) {
        allNums_.push_back(allBottomNums_.at(i));
    }
}

}