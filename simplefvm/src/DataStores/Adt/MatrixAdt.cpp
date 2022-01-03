#ifndef SIMPLEFVM_DATASTORES_ADT_MATRIXADT_H
#define SIMPLEFVM_DATASTORES_ADT_MATRIXADT_H

#include <cstddef>
#include <vector>

namespace datastores {

template <class T>
class MatrixAdt {
public:
    MatrixAdt();
    MatrixAdt(const size_t iSize, const size_t jSize);
    ~MatrixAdt();

    void create(const size_t iSize, const size_t jSize);
    T& getValue(const size_t i, const size_t j);
    void setValue(const size_t i, const size_t j, T& value);
    size_t get_iSize();
    size_t get_jSize();

private:
    std::vector<std::vector<T>> matrix_;
    size_t iSize_ = 0;                                          // row.
    size_t jSize_ = 0;                                          // column.

    void createMatrix(const size_t iSize, const size_t jSize);
    // bool checkIndexes(const size_t i, const size_t j);
};


template <class T>
MatrixAdt<T>::MatrixAdt() {

}

template <class T>
MatrixAdt<T>::MatrixAdt(const size_t iSize, const size_t jSize) {
    createMatrix(iSize, jSize);
}


template <class T>
MatrixAdt<T>::~MatrixAdt() {

}


template <class T>
void MatrixAdt<T>::create(const size_t iSize, const size_t jSize) {
    createMatrix(iSize, jSize);
}


template <class T>
T& MatrixAdt<T>::getValue(const size_t i, const size_t j) {
    return matrix_[i][j];
}


template <class T>
void MatrixAdt<T>::setValue(const size_t i, const size_t j, T& value) {
    matrix_[i][j] = value;
}


template <class T>
size_t MatrixAdt<T>::get_iSize() {
    return iSize_;
}


template <class T>
size_t MatrixAdt<T>::get_jSize() {
    return jSize_;
}


template <class T>
void MatrixAdt<T>::createMatrix(const size_t iSize, const size_t jSize) {
    matrix_.resize(iSize);
    for (size_t i = 0; i < iSize; i++) {
        matrix_.at(i).resize(jSize);
    }

    iSize_ = iSize;
    jSize_ = jSize;
}

// template <class T>
// bool MatrixAdt<T>::checkIndexes(const size_t i, const size_t j) {

//     if (((i < 0) || (i >= iSize_)) && ((j < 0) || (j >= jSize_))) {
//         return false;
//     } else {
//         return true;
//     }
// }

}
#endif // SIMPLEFVM_DATASTORES_ADT_MATRIXADT_H