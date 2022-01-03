#include "AdjCellsTypeStore.h"

namespace datastores {

AdjCellsTypeStore::AdjCellsTypeStore() {

}

void AdjCellsTypeStore::createArrays(size_t size) {
    cellTypes_.create(size);
}

ArrayAdt<EnumAdjacentCellTypes>& AdjCellsTypeStore::getCellType() {
    return cellTypes_;
}

}