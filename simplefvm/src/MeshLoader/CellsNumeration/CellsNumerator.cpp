#include "CellsNumerator.h"

namespace meshloader {


CellsNumerator::CellsNumerator(
                BaseMatrix& baseMatrix,
                BaseMatrix& templateMatrixP,
                NumsMatrix& interiorNumsMatrixP, 
                NumsMatrix& globalNumsMatrixP) : 
                        baseMatrix_(baseMatrix),
                        templateMatrixP_(templateMatrixP),
                        interiorNumsMatrixP_(interiorNumsMatrixP),
                        globalNumsMatrixP_(globalNumsMatrixP),
                        interiorCellsNumeratorP_(templateMatrixP,
                                                 interiorNumsMatrixP),
                        globalCellsNumeratorP_(baseMatrix,
                                               templateMatrixP,
                                               interiorNumsMatrixP,
                                               globalNumsMatrixP) {

}

void CellsNumerator::createNumeration() {
    interiorCellsNumeratorP_.numerateCells();
    globalCellsNumeratorP_.numerateCells(interiorCellsNumeratorP_.getLatestCellNum());
}

}