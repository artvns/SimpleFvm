#include "MeshInformationMask.h"

namespace meshloader {

MeshInformationMask::MeshInformationMask(
        RecievedDataStore& store) : store_(store) {

}

void MeshInformationMask::createStore(size_t parts) {
    store_.createArrays(parts);
}

std::vector<std::string>& MeshInformationMask::getBcNamesVector() {
    return store_.getBcNamesVector();
}

void MeshInformationMask::setPartName(size_t index, std::string value) {
    store_.getPartName().setValue(index, value);
}

void MeshInformationMask::setPartCellsAmount(std::string name, size_t value) {
    store_.getPartCellsAmount().addObject(name, value);
}

void MeshInformationMask::setDomainPartsAmount(size_t partsAmount) {
    store_.setDomainPartsAmount(partsAmount);
}

void MeshInformationMask::setAllCellsAmount(size_t allCellsAmount) {
    store_.setAllCellsAmount(allCellsAmount);
}

}