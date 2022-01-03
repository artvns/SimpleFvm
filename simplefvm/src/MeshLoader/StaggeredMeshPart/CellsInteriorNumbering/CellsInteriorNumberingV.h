#ifndef SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_INTERIORNUMBERINGV_H
#define SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_INTERIORNUMBERINGV_H

#include <vector>

#include "AbstractCellsInteriorNumbering.h"


namespace meshloader {

class CellsInteriorNumberingV : public AbstractCellsInteriorNumbering {
public:
    CellsInteriorNumberingV(Mesh& mesh, NumsSets& numsSets);

protected:
    void setInteriorNum(size_t globNum, size_t interNum) override;

private:

};

}
#endif // SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_CELLSINTERIORNUMBERING_INTERIORNUMBERINGV_H