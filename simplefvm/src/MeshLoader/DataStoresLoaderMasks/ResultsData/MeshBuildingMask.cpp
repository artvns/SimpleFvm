#include "MeshBuildingMask.h"

namespace meshloader {

MeshBuildingMask::MeshBuildingMask(
        RecievedDataStore& store) : store_(store) {

}

void MeshBuildingMask::createArrays(size_t activeCells, size_t gapCells) {
    store_.createArrays(activeCells, gapCells);
}

void MeshBuildingMask::setActiveCellsAmount(size_t value) {
    store_.setActiveCellsAmount(value);
}

void MeshBuildingMask::setGapCellsAmount(size_t value) {
    store_.setGapCellsAmount(value);
}

void MeshBuildingMask::setMeshSizeX(size_t value) {
    store_.setMeshSizeX(value);
}

void MeshBuildingMask::setMeshSizeY(size_t value) {
    store_.setMeshSizeY(value);
}

size_t MeshBuildingMask::getActiveCellNum(size_t pos) {
    return store_.getActiveCellNum().getValue(pos);
}

size_t MeshBuildingMask::getActiveCell_iPos(size_t pos) {
    return store_.getActiveCell_iPos().getValue(pos);
}

size_t MeshBuildingMask::getActiveCell_jPos(size_t pos) {
    return store_.getActiveCell_jPos().getValue(pos);
}

size_t MeshBuildingMask::getGapCellNum(size_t pos) {
    return store_.getGapCellNum().getValue(pos);
}

size_t MeshBuildingMask::getGapCell_iPos(size_t pos) {
    return store_.getGapCell_iPos().getValue(pos);
}

size_t MeshBuildingMask::getGapCell_jPos(size_t pos) {
    return store_.getGapCell_jPos().getValue(pos);
}

void MeshBuildingMask::setActiveCellNum(size_t pos, size_t value) {
    store_.getActiveCellNum().setValue(pos, value);
}

void MeshBuildingMask::setActiveCell_iPos(size_t pos, size_t value) {
    store_.getActiveCell_iPos().setValue(pos, value);
}

void MeshBuildingMask::setActiveCell_jPos(size_t pos, size_t value) {
    store_.getActiveCell_jPos().setValue(pos, value);
}

void MeshBuildingMask::setGapCellNum(size_t pos, size_t value) {
    store_.getGapCellNum().setValue(pos, value);
}

void MeshBuildingMask::setGapCell_iPos(size_t pos, size_t value) {
    store_.getGapCell_iPos().setValue(pos, value);
}

void MeshBuildingMask::setGapCell_jPos(size_t pos, size_t value) {
    store_.getGapCell_jPos().setValue(pos, value);
}

}