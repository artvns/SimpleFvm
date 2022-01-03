#include "SavedCoeffsStore.h"

namespace fvmsolver {

SavedCoeffsStore::SavedCoeffsStore() {

}


void SavedCoeffsStore::createArrays(const size_t size) {
    Ap_.resize(size);
    Aw_.resize(size);
    Ae_.resize(size);
    An_.resize(size);
    As_.resize(size);
}

std::vector<double>& SavedCoeffsStore::getAp() {
    return Ap_;
}

std::vector<double>& SavedCoeffsStore::getAw() {
    return Aw_;
}

std::vector<double>& SavedCoeffsStore::getAe() {
    return Ae_;
}

std::vector<double>& SavedCoeffsStore::getAn() {
    return An_;
}

std::vector<double>& SavedCoeffsStore::getAs() {
    return As_;
}

}