#ifndef SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_ABSTRACTINTERIORNUMBERING_H
#define SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_ABSTRACTINTERIORNUMBERING_H

#include <cstddef>
#include <vector>
#include <algorithm>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/LoaderDataStores/NumsSets.h"


namespace meshloader {

class AbstractCellsInteriorNumbering {
public:
    AbstractCellsInteriorNumbering(Mesh& mesh, NumsSets& numsSets);
    virtual ~AbstractCellsInteriorNumbering() = 0;

    void numberCells();

protected:
    Mesh& mesh_;
    NumsSets& numsSets_;
    std::vector<size_t> globNums_;

    virtual void setInteriorNum(size_t globNum, size_t interNum) = 0;
    
private:
    void combineNums();
    void sortVector(std::vector<size_t>& v);
    void removeDuplicatedValues(std::vector<size_t>& v);
};

}
#endif // SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_ABSTRACTINTERIORNUMBERING_H