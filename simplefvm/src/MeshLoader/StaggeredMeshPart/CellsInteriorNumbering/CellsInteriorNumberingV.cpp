#include "CellsInteriorNumberingV.h"

namespace meshloader {

CellsInteriorNumberingV::CellsInteriorNumberingV(
                    Mesh& mesh, NumsSets& numsSets) :
                            AbstractCellsInteriorNumbering(mesh, numsSets) {

}

void CellsInteriorNumberingV::setInteriorNum(size_t globNum, size_t interNum) {
    mesh_.getCell(globNum)->getCellV().setInteriorNum(interNum);
}

}