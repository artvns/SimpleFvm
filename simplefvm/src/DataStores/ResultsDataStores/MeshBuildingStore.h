#ifndef SIMPLEFVM_DATASTORES_RESULTSDATASTORES_MESHBUILDINGSTORE_H
#define SIMPLEFVM_DATASTORES_RESULTSDATASTORES_MESHBUILDINGSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class MeshBuildingStore {
public:
    MeshBuildingStore();

    void createArrays(size_t activeCells, size_t gapCells);

    size_t getActiveCellsAmount() const;
    void setActiveCellsAmount(size_t value);

    size_t getGapCellsAmount() const;
    void setGapCellsAmount(size_t value);

    size_t getMeshSizeX() const;
    void setMeshSizeX(size_t value);

    size_t getMeshSizeY() const;
    void setMeshSizeY(size_t value);

    ArrayAdt<size_t>& getActiveCellNum();
    ArrayAdt<size_t>& getActiveCell_iPos();
    ArrayAdt<size_t>& getActiveCell_jPos();

    ArrayAdt<size_t>& getGapCellNum();
    ArrayAdt<size_t>& getGapCell_iPos();
    ArrayAdt<size_t>& getGapCell_jPos();

private:
    size_t activeCellsAmount_ = 0;
    size_t gapCellsAmount_ = 0;
    size_t meshSizeX_ = 0;    
    size_t meshSizeY_ = 0;

    ArrayAdt<size_t> activeCellNum_;
    ArrayAdt<size_t> activeCell_iPos_;
    ArrayAdt<size_t> activeCell_jPos_;

    ArrayAdt<size_t> gapCellNum_;
    ArrayAdt<size_t> gapCell_iPos_;
    ArrayAdt<size_t> gapCell_jPos_;
};

}
#endif // SIMPLEFVM_DATASTORES_RESULTSDATASTORES_MESHBUILDINGSTORE_H