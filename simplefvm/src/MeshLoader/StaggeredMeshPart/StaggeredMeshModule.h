#ifndef SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_STAGGEREDMESHMODULE_H
#define SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_STAGGEREDMESHMODULE_H

#include <string>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/LoaderDataStores/NumsSets.h"

#include "./VelocityNumberingSets/NumsSetsCreatorU.h"
#include "./VelocityNumberingSets/NumsSetsCreatorV.h"
#include "./CellsInteriorNumbering/CellsInteriorNumberingU.h"
#include "./CellsInteriorNumbering/CellsInteriorNumberingV.h"


namespace meshloader {

class StaggeredMeshModule {
public:
    StaggeredMeshModule(Mesh& meshContainer, NumsSets& numsSetsP);

    void createVelocityNumsSets(NumsSets& numsSetsU, 
                                NumsSets& numsSetsV);

private:
    Mesh& meshContainer_;
    NumsSets& numsSetsP_;

    void createNumsSetsU(NumsSets& numsSetsU);
    void createNumsSetsV(NumsSets& numsSetsV);
};

}
#endif // SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_STAGGEREDMESHMODULE_H