#include "SavedRhsStore.h"

namespace fvmsolver {

SavedRhsStore::SavedRhsStore() {

}

void SavedRhsStore::createArrays(const size_t size) {
    resizeVector(rhs_, size);
    resizeVector(b_, size);
}

double SavedRhsStore::getRhs(const size_t pos)  const {
    return rhs_.at(pos);
}

void SavedRhsStore::setRhs(const size_t pos, double value) {
    rhs_.at(pos) = value;
}

double SavedRhsStore::get_b(const size_t pos) const {
    return b_.at(pos);
}

void SavedRhsStore::set_b(const size_t pos, double value) {
    b_.at(pos) = value;
}

void SavedRhsStore::resizeVector(std::vector<double>& array, 
                                            const size_t size) {
    array.resize(size);
}

}