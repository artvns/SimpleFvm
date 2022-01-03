#include "MainDataPacker.h"

namespace meshloader {

MainDataPacker::MainDataPacker(
            DataStoreMasks& dataContainer, 
            Mesh& mesh, 
            NumsSets& numsSetsP, 
            NumsSets& numsSetsU, 
            NumsSets& numsSetsV) :
                        fieldsPacker_     (dataContainer, mesh),
                        meshParamsPacker_ (dataContainer, mesh),
                        numsPackerP_      (dataContainer, mesh, numsSetsP),
                        numsPackerU_      (dataContainer, mesh, numsSetsU),
                        numsPackerV_      (dataContainer, mesh, numsSetsV),
                        cellTypesPacker_  (dataContainer, mesh),
                        meshInfoPacker_   (dataContainer, numsSetsP, 
                                                          numsSetsU, 
                                                          numsSetsV) {

}

void MainDataPacker::packData() {
    fieldsPacker_.packFields();
    meshParamsPacker_.packMeshParameters();
    numsPackerP_.packAll();
    numsPackerU_.packAll();
    numsPackerV_.packAll();
    cellTypesPacker_.packCellTypes();
    meshInfoPacker_.packMeshInfo();
}

}