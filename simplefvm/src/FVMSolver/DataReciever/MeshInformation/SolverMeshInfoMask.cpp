#include "SolverMeshInfoMask.h"

namespace fvmsolver {

SolverMeshInfoMask::SolverMeshInfoMask(
        RecievedDataStore& store) : store_(store) {

}

std::string SolverMeshInfoMask::getPartName (size_t index) const {
    return store_.getPartName().getValue(index);
}

size_t SolverMeshInfoMask::getPartCellsAmount(std::string name) const {
    return store_.getPartCellsAmount().getObject(name);
}

size_t SolverMeshInfoMask::getDomainPartsAmount() const {
    return store_.getDomainPartsAmount();
}

size_t SolverMeshInfoMask::getAllCellsAmount() const {
    return store_.getAllCellsAmount();
}

}