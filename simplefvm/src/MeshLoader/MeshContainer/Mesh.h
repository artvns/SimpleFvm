#ifndef SIMPLEFVM_MESHLOADER_MESHCONTAINER_MESH_H
#define SIMPLEFVM_MESHLOADER_MESHCONTAINER_MESH_H

/*
*   Grid class with generated dependencies.
*/


#include <cstddef>
#include <vector>

#include "MacroCell.h"


namespace meshloader {

class Mesh {
private:
    using uPtrMacroCell = std::unique_ptr<MacroCell>;

public:
    Mesh();

    void placeCellNumIndexByGlobalCellNum();
    void defineMeshAsLinked();
    bool isLinked();

    void addCell(uPtrMacroCell ptr);
    uPtrMacroCell& getCell(const size_t globalNum);
    uPtrMacroCell& getCellByIndex(const size_t index);
    size_t getCellsAmount();

    uPtrMacroCell& getAdjCellW(const size_t globalNum);
    uPtrMacroCell& getAdjCellE(const size_t globalNum);
    uPtrMacroCell& getAdjCellN(const size_t globalNum);
    uPtrMacroCell& getAdjCellS(const size_t globalNum);

private:
    std::vector<uPtrMacroCell> mesh_;
    std::vector<size_t> cellIndexByGlobalCellNum_;
    bool isLinked_ = false;

    size_t findCellIndex(const size_t globalNum);
};

}
#endif // SIMPLEFVM_MESHLOADER_MESHCONTAINER_MESH_H