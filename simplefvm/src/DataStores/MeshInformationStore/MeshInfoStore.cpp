#include "MeshInfoStore.h"

namespace datastores {

MeshInfoStore::MeshInfoStore() {

}

void MeshInfoStore::createArrays(size_t parts) {
    partCellsAmount_.clearMap();
    partNames_.create(parts);
}

size_t MeshInfoStore::getDomainPartsAmount() const {
    return domainPartsAmount_;
}

void MeshInfoStore::setDomainPartsAmount(size_t partsAmount) {
    domainPartsAmount_ = partsAmount;
}

size_t MeshInfoStore::getAllCellsAmount() const {
    return allCellsAmount_;
}

void MeshInfoStore::setAllCellsAmount(size_t allCellsAmount) {
    allCellsAmount_ = allCellsAmount;
}

ArrayAdt<std::string>& MeshInfoStore::getPartName() {
    return partNames_;
}

MapAdt<size_t>& MeshInfoStore::getPartCellsAmount() {
    return partCellsAmount_;
}

std::vector<std::string>& MeshInfoStore::getBcNamesVector() {
    return bcNamesVector_;
}

}