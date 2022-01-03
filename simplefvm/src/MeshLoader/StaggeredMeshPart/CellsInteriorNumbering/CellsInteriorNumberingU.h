#ifndef SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_INTERIORNUMBERINGU_H
#define SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_INTERIORNUMBERINGU_H

#include <vector>

#include "AbstractCellsInteriorNumbering.h"


namespace meshloader {

class CellsInteriorNumberingU : public AbstractCellsInteriorNumbering {
public:
    CellsInteriorNumberingU(Mesh& mesh, NumsSets& numsSets);

protected:
    void setInteriorNum(size_t globNum, size_t interNum) override;

private:

};

}
#endif // SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_INTERIORNUMBERINGU_H