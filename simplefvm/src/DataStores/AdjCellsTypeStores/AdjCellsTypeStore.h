#ifndef SIMPLEFVM_DATASTORES_ADJCELLSTYPESTORES_ADJCELLSTYPESTORE_H
#define SIMPLEFVM_DATASTORES_ADJCELLSTYPESTORES_ADJCELLSTYPESTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

/*
*	Cell types:
*	- ADJACENT_CELL_INTERIOR - inner adjacent cell;
*	- ADJACENT_CELL_REAL_BC  - border real adjacent cell;
*	- ADJACENT_CELL_GHOST_BC - virtual adjacent cell;
*/

enum EnumAdjacentCellTypes {
	ADJACENT_CELL_INTERIOR,
	ADJACENT_CELL_BC_REAL,
	ADJACENT_CELL_BC_GHOST
};


class AdjCellsTypeStore {
public:
    AdjCellsTypeStore();
    
    void createArrays(size_t size);

    ArrayAdt<EnumAdjacentCellTypes>& getCellType();

private:
    ArrayAdt<EnumAdjacentCellTypes> cellTypes_;
};

}
#endif // SIMPLEFVM_DATASTORES_ADJCELLSTYPESTORES_ADJCELLSTYPESTORE_H