#ifndef SIMPLEFVM_MESHLOADER_MESHCONTAINER_CELLSSIZEDEFINER_H
#define SIMPLEFVM_MESHLOADER_MESHCONTAINER_CELLSSIZEDEFINER_H

#include <cstddef>

#include "Mesh.h"


namespace meshloader {

class CellsSizeDefiner {
public:
    CellsSizeDefiner();

    void setCellsSize(Mesh& meshContainer, const double dx, const double dy);

private:

};

}
#endif // SIMPLEFVM_MESHLOADER_MESHCONTAINER_CELLSSIZEDEFINER_H