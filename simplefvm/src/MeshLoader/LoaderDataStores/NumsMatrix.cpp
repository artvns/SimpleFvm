#include "NumsMatrix.h"

namespace meshloader {

NumsMatrix::NumsMatrix() {

}

void NumsMatrix::createMatrix(size_t rows, size_t cols) {
    matrix_.resize(rows);
    
    for (size_t i = 0; i < rows; i++) {
        matrix_.at(i).resize(cols);
    }
    rows_ = rows;
    cols_ = cols;
}

size_t NumsMatrix::getValue(size_t i, size_t j) const {
    return matrix_[i][j];
}

void NumsMatrix::setValue(size_t i, size_t j, size_t value) {
    matrix_[i][j] = value;
}

size_t NumsMatrix::getRowsAmount() const {
    return rows_;
}

size_t NumsMatrix::getColsAmount() const {
    return cols_;
}

}