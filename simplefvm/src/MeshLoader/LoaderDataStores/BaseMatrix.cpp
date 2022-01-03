#include "BaseMatrix.h"

namespace meshloader {

BaseMatrix::BaseMatrix() {

}

void BaseMatrix::createMatrix(size_t rows, size_t cols) {
    matrix_.resize(rows);

    for (size_t i = 0; i < rows; i++) {
        matrix_.at(i).resize(cols);
    }
    rows_ = rows;
    cols_ = cols;
}

char BaseMatrix::getValue(size_t i, size_t j) const {
    return matrix_[i][j];
}

void BaseMatrix::setValue(size_t i, size_t j, char value) {
    matrix_[i][j] = value;
}

size_t BaseMatrix::getRowsAmount() const {
    return rows_;
}

size_t BaseMatrix::getColsAmount() const {
    return cols_;
}

}