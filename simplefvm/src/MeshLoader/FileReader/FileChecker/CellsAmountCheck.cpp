#include "CellsAmountCheck.h"

namespace meshloader {

CellsAmountCheck::CellsAmountCheck() {

}

void CellsAmountCheck::checkCellsMaxAmount(const size_t currentCellsAmount) {
    if (std::numeric_limits<int>::max() < currentCellsAmount ) {
        throw std::range_error(
                "the number of grid cells is more then max int...");
    }
}

}