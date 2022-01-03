#include "StaggeredMeshModule.h"

namespace meshloader {

StaggeredMeshModule::StaggeredMeshModule(
                        Mesh& meshContainer, 
                        NumsSets& numsSetsP) :
                                    meshContainer_(meshContainer),
                                    numsSetsP_(numsSetsP) {

}

void StaggeredMeshModule::createVelocityNumsSets(
                    NumsSets& numsSetsU, NumsSets& numsSetsV) {

    createNumsSetsU(numsSetsU);
    createNumsSetsV(numsSetsV);
}

void StaggeredMeshModule::createNumsSetsU(NumsSets& numsSetsU) {
    NumsSetsCreatorU numsSetsCreatorU_(meshContainer_, numsSetsP_, numsSetsU);
    numsSetsCreatorU_.createNamedSets();

    CellsInteriorNumberingU interiorNumberingU_(meshContainer_, numsSetsU);
    interiorNumberingU_.numberCells();
}

void StaggeredMeshModule::createNumsSetsV(NumsSets& numsSetsV) {
    NumsSetsCreatorV numsSetsCreatorV_(meshContainer_, numsSetsP_, numsSetsV);
    numsSetsCreatorV_.createNamedSets();

    CellsInteriorNumberingV interiorNumberingV_(meshContainer_, numsSetsV);
    interiorNumberingV_.numberCells();
}

}