#ifndef SIMPLEFVM_DATASTORES_ADT_ARRAYADT_H
#define SIMPLEFVM_DATASTORES_ADT_ARRAYADT_H

#include <cstddef>
#include <vector>
#include <stdexcept>


namespace datastores {

template <class T>
class ArrayAdt {
public:
    ArrayAdt();
    ArrayAdt(const size_t size);
    ~ArrayAdt();

    void    create(const size_t size);
    T&      operator[](const size_t i);
    T&      getValue(const size_t i);
    void    setValue(const size_t i, T value);
    size_t  getSize();

private:
    std::vector<T> array_;
    size_t size_ = 0;

    void createArray(const size_t size);
};



template <class T>
ArrayAdt<T>::ArrayAdt() {

}

template <class T>
ArrayAdt<T>::ArrayAdt(const size_t size) {
    createArray(size);
}


template <class T>
ArrayAdt<T>::~ArrayAdt() {
 
}


template <class T>
void ArrayAdt<T>::create(const size_t size) {
    createArray(size);
}

template <class T>
T& ArrayAdt<T>::operator[](const size_t i) {
    return array_.at(i);
}


template <class T>
T& ArrayAdt<T>::getValue(const size_t i) {
    return array_.at(i);
}

template <class T>
void ArrayAdt<T>::setValue(const size_t i, T value) {
    array_.at(i) = value;
}


template <class T>
size_t ArrayAdt<T>::getSize() {
    return size_;
}


template <class T>
void ArrayAdt<T>::createArray(const size_t size) {
    array_.clear();
    array_.resize(size);
    size_ = size;
}

}
#endif // SIMPLEFVM_DATASTORES_ADT_ARRAYADT_H


