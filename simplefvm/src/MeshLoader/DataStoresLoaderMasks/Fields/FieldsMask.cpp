#include "FieldsMask.h"

namespace meshloader {

FieldsMask::FieldsMask(RecievedDataStore& store) : store_(store) {

}

void FieldsMask::createStore(size_t uSize, size_t vSize, size_t pSize) {
    store_.createArrays(uSize, vSize, pSize);
}

void FieldsMask::setU(size_t index, double value) {
    store_.get_u().setValue(index, value);
}

void FieldsMask::setV(size_t index, double value) {
    store_.get_v().setValue(index, value);
}

void FieldsMask::setP(size_t index, double value) {
    store_.get_p().setValue(index, value);
}

}