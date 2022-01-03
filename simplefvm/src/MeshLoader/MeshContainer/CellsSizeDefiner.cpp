#include "CellsSizeDefiner.h"

namespace meshloader {

CellsSizeDefiner::CellsSizeDefiner() {

}

void CellsSizeDefiner::setCellsSize(Mesh& meshContainer, 
                                        const double dx, const double dy) {
                                            
    for (size_t i = 0; i < meshContainer.getCellsAmount(); ++i) {
        meshContainer.getCellByIndex(i)->getCellU().set_dX(dx);
        meshContainer.getCellByIndex(i)->getCellV().set_dX(dx);
        meshContainer.getCellByIndex(i)->getCellP().set_dX(dx);

        meshContainer.getCellByIndex(i)->getCellU().set_dY(dy);
        meshContainer.getCellByIndex(i)->getCellV().set_dY(dy);
        meshContainer.getCellByIndex(i)->getCellP().set_dY(dy);
    }
}

}