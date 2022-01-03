#include "AdjCellsTypeMask.h"

namespace meshloader {

AdjCellsTypeMask::AdjCellsTypeMask(
    RecievedDataStore& store) : store_(store) {

}

void AdjCellsTypeMask::createStore(size_t size) {
    store_.createArrays(size);
}

void AdjCellsTypeMask::setCellTypeAsInterior(size_t index) {
    store_.getCellType().setValue(
        index, AdjCellType::ADJACENT_CELL_INTERIOR);
}

void AdjCellsTypeMask::setCellTypeAsBcReal(size_t index) {
    store_.getCellType().setValue(
        index, AdjCellType::ADJACENT_CELL_BC_REAL);
}

void AdjCellsTypeMask::setCellTypeAsBcGhost(size_t index) {
    store_.getCellType().setValue(
        index, AdjCellType::ADJACENT_CELL_BC_GHOST);
}

}