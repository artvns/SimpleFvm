#include "InteriorCellsNumerator.h"

namespace meshloader {

InteriorCellsNumerator::InteriorCellsNumerator(
                        BaseMatrix& templateMatrixP,
                        NumsMatrix& interiorNumsMatrixP) : 
                                templateMatrixP_(templateMatrixP),
                                interiorNumsMatrixP_(interiorNumsMatrixP) {

}

void InteriorCellsNumerator::numerateCells() {
    createMatrix();

    size_t cellNum = 1;

    for (size_t i = 0; i < maxLines_; i++) {
        for (size_t j = 0; j < maxColumns_; j++) {
            if('0' != templateMatrixP_.getValue(i,j)) {
                interiorNumsMatrixP_.setValue(i, j, cellNum);
                cellNum++;
            }
            else {
                interiorNumsMatrixP_.setValue(i, j, 0);
            }
        }
    }
    latestCellNum_ = cellNum;
}

void InteriorCellsNumerator::createMatrix() {
    maxLines_ = templateMatrixP_.getRowsAmount();
    maxColumns_ = templateMatrixP_.getColsAmount();

    interiorNumsMatrixP_.createMatrix(maxLines_, maxColumns_);
}

size_t  InteriorCellsNumerator::getLatestCellNum() {
    return latestCellNum_;
}

}