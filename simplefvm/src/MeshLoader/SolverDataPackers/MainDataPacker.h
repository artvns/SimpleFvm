#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MAINDATAPACKER_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MAINDATAPACKER_H

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/LoaderDataStores/NumsSets.h"
#include "MeshLoader/DataStoresLoaderMasks/DataStoreMasks.h"

#include "./CellNumsPacker/NumsPackerP.h"
#include "./CellNumsPacker/NumsPackerU.h"
#include "./CellNumsPacker/NumsPackerV.h"

#include "FieldsPacker.h"
#include "MeshParamsPacker.h"
#include "CellTypesPacker.h"
#include "MeshInfoPacker.h"


namespace meshloader {

class MainDataPacker {
public:
    MainDataPacker(DataStoreMasks& dataContainer, 
                    Mesh& mesh, 
                    NumsSets& numsSetsP, 
                    NumsSets& numsSetsU, 
                    NumsSets& numsSetsV);

    void packData();

private:
    FieldsPacker          fieldsPacker_;
    MeshParamsPacker      meshParamsPacker_;
    NumsPackerP           numsPackerP_;
    NumsPackerU           numsPackerU_;
    NumsPackerV           numsPackerV_;
    CellTypesPacker       cellTypesPacker_;
    MeshInfoPacker        meshInfoPacker_;

    void aggregateCellNums();
};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MAINDATAPACKER_H