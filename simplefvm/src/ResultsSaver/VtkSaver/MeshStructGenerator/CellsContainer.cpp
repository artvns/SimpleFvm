#include "CellsContainer.h"

namespace resultssaver {

CellsContainer::CellsContainer() {

}

CellsContainer::uPtrSaverCellVector& CellsContainer::getContainer() {
    return cellsContainer_;
}

CellsContainer::uPtrSaverCell& CellsContainer::getCell(size_t index) {
    return cellsContainer_.at(index);
}

size_t CellsContainer::getCellsAmount() const {
    return cellsContainer_.size();
}

}