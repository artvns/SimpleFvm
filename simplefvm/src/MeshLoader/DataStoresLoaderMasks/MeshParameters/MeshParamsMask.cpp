#include "MeshParamsMask.h"

namespace meshloader {

MeshParamsMask::MeshParamsMask(
    RecievedDataStore& store) : store_(store) {

}

void MeshParamsMask::createStore(size_t size) {
    store_.createArrays(size);
}

void MeshParamsMask::set_dX(size_t index, double value) {
    store_.get_dX().setValue(index, value);
}

void MeshParamsMask::set_dY(size_t index, double value) {
    store_.get_dY().setValue(index, value);
}

}