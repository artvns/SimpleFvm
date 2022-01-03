#include "MeshTemplateP.h"

namespace meshloader {

MeshTemplateP::MeshTemplateP(
                    BaseMatrix& baseMatrix, 
                    BaseMatrix& templateMatrixP) : 
                                baseMatrix_(baseMatrix),
                                templateMatrixP_(templateMatrixP) {

}

void MeshTemplateP::createTemplate() {
    createMatrix();
    initializeWithZeroes();

    for (size_t i = 0; i < baseMatrix_.getRowsAmount(); i++) {
        for (size_t j = 0; j < baseMatrix_.getColsAmount(); j++) {
            if('0' != baseMatrix_.getValue(i, j)) {
                templateMatrixP_.setValue(
                    i + 1,
                    j + 1,
                    baseMatrix_.getValue(i, j)
                );
            }
        }
    }
}

void MeshTemplateP::createMatrix() {
    maxLines_  = baseMatrix_.getRowsAmount() + 2;
    maxColumns_ = baseMatrix_.getColsAmount() + 2;

    templateMatrixP_.createMatrix(maxLines_, maxColumns_);
}

void MeshTemplateP::initializeWithZeroes() {
    for (size_t i = 0; i < maxLines_; i++) {
        for (size_t j = 0; j < maxColumns_; j++) {
            templateMatrixP_.setValue(i, j, '0');
        }
    }
}

}