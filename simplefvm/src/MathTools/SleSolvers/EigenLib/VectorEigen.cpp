#include "VectorEigen.h"

namespace mathtools {

VectorEigen::VectorEigen() {

}

void VectorEigen::createVector(const size_t size) {
    pVector_.resize(size);
}

double VectorEigen::getValue(size_t i) {
    return pVector_(i); 
}

void VectorEigen::setValue(size_t i, double value) {
    pVector_(i) = value;
}

size_t VectorEigen::getSize() {
    return pVector_.size();
}

Eigen::VectorXd& VectorEigen::getVector() {
    return pVector_;
}

}