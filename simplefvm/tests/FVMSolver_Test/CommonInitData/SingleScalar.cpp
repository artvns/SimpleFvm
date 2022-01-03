#include "SingleScalar.h"

namespace commoninitdata {

SingleScalar::SingleScalar() {

}

void SingleScalar::createVector(size_t size) {
    dataVector_.resize(size);
}

double SingleScalar::getValue(size_t i) {
    return dataVector_.at(i); 
}

void SingleScalar::setValue(size_t i, double value) {
    dataVector_.at(i) = value;
}

size_t SingleScalar::getSize() {
    return dataVector_.size(); 
}

std::vector<double> SingleScalar::getVector() {
    return dataVector_;
}

}