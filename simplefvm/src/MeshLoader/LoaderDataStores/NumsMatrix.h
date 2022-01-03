#ifndef SIMPLEFVM_MESHLOADER_LOADERDATASTORES_NUMSMATRIX_H
#define SIMPLEFVM_MESHLOADER_LOADERDATASTORES_NUMSMATRIX_H

#include <cstddef>
#include <vector>
#include <iostream>


namespace meshloader {

class NumsMatrix {
public:
    NumsMatrix();

    void createMatrix(size_t rows, size_t cols);
    size_t getValue(size_t i, size_t j) const;
    void setValue(size_t i, size_t j, size_t value);
    size_t getRowsAmount() const;
    size_t getColsAmount() const;

private:
    std::vector<std::vector<size_t>> matrix_;
    size_t rows_ = 0;
    size_t cols_ = 0;
};

}
#endif // SIMPLEFVM_MESHLOADER_LOADERDATASTORES_NUMSMATRIX_H