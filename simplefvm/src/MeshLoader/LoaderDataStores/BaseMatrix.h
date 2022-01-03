#ifndef SIMPLEFVM_MESHLOADER_LOADERDATASTORES_BASEMATRIX_H
#define SIMPLEFVM_MESHLOADER_LOADERDATASTORES_BASEMATRIX_H

#include <cstddef>
#include <vector>


namespace meshloader {

class BaseMatrix {
public:
    BaseMatrix();

    void createMatrix(size_t rows, size_t cols);
    char getValue(size_t i, size_t j) const;
    void setValue(size_t i, size_t j, char value);
    size_t getRowsAmount() const;
    size_t getColsAmount() const;

private:
    std::vector<std::vector<char>> matrix_;
    size_t rows_ = 0;
    size_t cols_ = 0;
};

}
#endif // SIMPLEFVM_MESHLOADER_LOADERDATASTORES_BASEMATRIX_H