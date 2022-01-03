#include "MeshInformation.h"

namespace meshloader {

MeshInformation::MeshInformation() {

}

void MeshInformation::addFaceParameters(std::string faceName, size_t cellsAmount) {
    if(!isAlreadyAdded(faceName)) {
        numberOfParts_++;
        faceName_.push_back(faceName);
        cellsAmount_.push_back(cellsAmount);
    }
}

size_t MeshInformation::getNumberOfParts() const {
    return numberOfParts_;
}

std::string MeshInformation::getFaceName(const size_t i) const {
    return faceName_.at(i);
}

size_t MeshInformation::getFaceCellsAmount(const size_t i) const {
    return cellsAmount_.at(i);
}

bool MeshInformation::isAlreadyAdded(const std::string faceName) {
    bool isAlreadyAdded_ = false;

    for (size_t i = 0; i < faceName_.size(); i++) {
        if (faceName == faceName_.at(i)) {
            isAlreadyAdded_ = true;
        }
    }
    return isAlreadyAdded_;
}

}