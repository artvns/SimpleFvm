#include "MeshBuildingStore.h"

namespace datastores {

MeshBuildingStore::MeshBuildingStore() {

}

void MeshBuildingStore::createArrays(size_t activeCells, size_t gapCells) {
    activeCellNum_.create(activeCells);
    activeCell_iPos_.create(activeCells);
    activeCell_jPos_.create(activeCells);

    if (gapCells > 0) {
        gapCellNum_.create(gapCells);
        gapCell_iPos_.create(gapCells);
        gapCell_jPos_.create(gapCells);
    }
}

size_t MeshBuildingStore::getActiveCellsAmount() const {
    return activeCellsAmount_;
}

void MeshBuildingStore::setActiveCellsAmount(size_t value) {
    activeCellsAmount_ = value;
}

size_t MeshBuildingStore::getGapCellsAmount() const {
    return gapCellsAmount_;
}

void MeshBuildingStore::setGapCellsAmount(size_t value) {
    gapCellsAmount_ = value;
}

size_t MeshBuildingStore::getMeshSizeX() const {
    return meshSizeX_;
}

void MeshBuildingStore::setMeshSizeX(size_t value) {
    meshSizeX_ = value;
}

size_t MeshBuildingStore::getMeshSizeY() const {
    return meshSizeY_;
}

void MeshBuildingStore::setMeshSizeY(size_t value) {
    meshSizeY_ = value;
}

ArrayAdt<size_t>& MeshBuildingStore::getActiveCellNum() {
    return activeCellNum_;
}

ArrayAdt<size_t>& MeshBuildingStore::getActiveCell_iPos() {
    return activeCell_iPos_;
}

ArrayAdt<size_t>& MeshBuildingStore::getActiveCell_jPos() {
    return activeCell_jPos_;
}

ArrayAdt<size_t>& MeshBuildingStore::getGapCellNum() {
    return gapCellNum_;
}

ArrayAdt<size_t>& MeshBuildingStore::getGapCell_iPos() {
    return gapCell_iPos_;
}

ArrayAdt<size_t>& MeshBuildingStore::getGapCell_jPos() {
    return gapCell_jPos_;
}

}