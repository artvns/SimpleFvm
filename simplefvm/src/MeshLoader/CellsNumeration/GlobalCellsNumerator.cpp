#include "GlobalCellsNumerator.h"

namespace meshloader {

GlobalCellsNumerator::GlobalCellsNumerator(
                    BaseMatrix& baseMatrix,
                    BaseMatrix& templateMatrixP, 
                    NumsMatrix& interiorNumsMatrixP,
                    NumsMatrix& globalNumsMatrixP) : 
                                    baseMatrix_(baseMatrix),
                                    templateMatrixP_(templateMatrixP),
                                    interiorNumsMatrixP_(interiorNumsMatrixP),
                                    globalNumsMatrixP_(globalNumsMatrixP) {

}

void GlobalCellsNumerator::numerateCells(size_t maxInteriorCellNum) {
    createMatrix();
    insertInteriorNums();

    size_t cellNum = maxInteriorCellNum;
    size_t readerlines_ = baseMatrix_.getRowsAmount();
    size_t readercols_ = baseMatrix_.getColsAmount();

    for (size_t i = 0; i < readerlines_; i++) {
        for (size_t j = 0; j < readercols_; j++) {

            if('0' != templateMatrixP_.getValue(i + 1,j + 1)) {
                // Side w. 
                if (0 == globalNumsMatrixP_.getValue(i + 1, j)) {
                    globalNumsMatrixP_.setValue(i + 1, j, cellNum);
                    cellNum++;
                }
                // Side e.
                if (0 == globalNumsMatrixP_.getValue(i + 1, j + 2)) {
                    globalNumsMatrixP_.setValue(i + 1, j + 2, cellNum);
                    cellNum++;
                }
                // Side n.
                if (0 == globalNumsMatrixP_.getValue(i, j + 1)) {
                    globalNumsMatrixP_.setValue(i, j + 1, cellNum);
                    cellNum++;
                }
                // Side s.
                if (0 == globalNumsMatrixP_.getValue(i + 2, j + 1)) {
                    globalNumsMatrixP_.setValue(i + 2, j + 1, cellNum);
                    cellNum++;
                }
            }
        }
    }
}

void GlobalCellsNumerator::createMatrix() {
    maxLines_ = templateMatrixP_.getRowsAmount();
    maxColumns_ = templateMatrixP_.getColsAmount();

    globalNumsMatrixP_.createMatrix(maxLines_, maxColumns_);
}

void GlobalCellsNumerator::insertInteriorNums() {
    for (size_t i = 0; i < maxLines_; i++) {
        for (size_t j = 0; j < maxColumns_; j++) {
            globalNumsMatrixP_.setValue(
                i, 
                j, 
                interiorNumsMatrixP_.getValue(i, j)
            );
        }
    }
}

}