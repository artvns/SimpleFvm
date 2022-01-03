#include "CellsInteriorNumberingU.h"

namespace meshloader {

CellsInteriorNumberingU::CellsInteriorNumberingU(
                    Mesh& mesh, NumsSets& numsSets) :
                            AbstractCellsInteriorNumbering(mesh, numsSets) {

}

void CellsInteriorNumberingU::setInteriorNum(size_t globNum, size_t interNum) {
    mesh_.getCell(globNum)->getCellU().setInteriorNum(interNum);
}

}