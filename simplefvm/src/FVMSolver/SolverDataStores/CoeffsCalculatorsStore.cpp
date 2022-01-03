#include "CoeffsCalculatorsStore.h"

namespace fvmsolver {

CoeffsCalculatorsStore::CoeffsCalculatorsStore() {

}

void CoeffsCalculatorsStore::createArrays(const size_t uSize, 
                                                const size_t vSize) {
    resizeVector(deU_, uSize);
    resizeVector(deV_, vSize);
}

double CoeffsCalculatorsStore::get_deU(const size_t pos) const {
    return deU_.at(pos);
}

void CoeffsCalculatorsStore::set_deU(const size_t pos, double value) {
    deU_.at(pos) = value;
}

double CoeffsCalculatorsStore::get_deV(const size_t pos) const {
    return deV_.at(pos);
}

void CoeffsCalculatorsStore::set_deV(const size_t pos, double value) {
    deV_.at(pos) = value;
}

void CoeffsCalculatorsStore::resizeVector(std::vector<double>& array, 
                                                    const size_t size) {
    array.resize(size);
}

}