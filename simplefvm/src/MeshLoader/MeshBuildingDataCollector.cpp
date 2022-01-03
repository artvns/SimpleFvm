#include "MeshBuildingDataCollector.h"

namespace meshloader {

MeshBuildingDataCollector::MeshBuildingDataCollector(
            MeshBuildingMask& meshBuildingMask,
            NumsMatrix& interiorNumsMatrixP,
            NumsMatrix& globalNumsMatrixP) :
                                meshBuildingMask_(meshBuildingMask),
                                interiorNumsMatrixP_(interiorNumsMatrixP),
                                globalNumsMatrixP_(globalNumsMatrixP) {

}

void MeshBuildingDataCollector::createDataStore() {
    meshColumns_ = interiorNumsMatrixP_.getColsAmount() - 2;
    meshRows_ = interiorNumsMatrixP_.getRowsAmount() - 2;

    activeCells_ = 0;
    gapCells_ = 0;

    // Counting the number of active cells and gap cells.
    for (size_t i = 0; i < meshRows_; i++) {
        for (size_t j = 0; j < meshColumns_; j++) {

            if (0 != getInteriorNum(i, j)) {
                activeCells_++;
            }
            else if (0 == getInteriorNum(i, j)) {
                gapCells_++;
            }
        }
    }

    meshBuildingMask_.createArrays(activeCells_, gapCells_);
}

void MeshBuildingDataCollector::fillDataStore() {
    meshBuildingMask_.setActiveCellsAmount(activeCells_);
    meshBuildingMask_.setGapCellsAmount(gapCells_);
    meshBuildingMask_.setMeshSizeX(meshColumns_);
    meshBuildingMask_.setMeshSizeY(meshRows_);

    size_t actCellsPos = 0;
    size_t gapCellsPos = 0;

    for (size_t i = 0; i < meshRows_; i++) {
        for (size_t j = 0; j < meshColumns_; j++) {

            if (0 != getInteriorNum(i, j)) {
                meshBuildingMask_.setActiveCellNum(actCellsPos, getGlobalNum(i, j));
                meshBuildingMask_.setActiveCell_iPos(actCellsPos, i);
                meshBuildingMask_.setActiveCell_jPos(actCellsPos, j);

                actCellsPos++;
            }
            else if (0 == getInteriorNum(i, j)) {
                meshBuildingMask_.setGapCellNum(gapCellsPos, getGlobalNum(i, j));
                meshBuildingMask_.setGapCell_iPos(gapCellsPos, i);
                meshBuildingMask_.setGapCell_jPos(gapCellsPos, j);

                gapCellsPos++;
            }
        }
    }
}

size_t MeshBuildingDataCollector::getInteriorNum(size_t i, size_t j) {
    i++;
    j++;
    return interiorNumsMatrixP_.getValue(i, j);
}

size_t MeshBuildingDataCollector::getGlobalNum(size_t i, size_t j) {
    i++;
    j++;
    return globalNumsMatrixP_.getValue(i, j);
}

}