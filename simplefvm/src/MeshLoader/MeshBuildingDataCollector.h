#ifndef SIMPLEFVM_MESHLOADER_MESHBUILDINGDATACOLLECTOR_H
#define SIMPLEFVM_MESHLOADER_MESHBUILDINGDATACOLLECTOR_H

#include <cstddef>
#include <string>

#include "MeshLoader/LoaderDataStores/NumsMatrix.h"
#include "MeshLoader/DataStoresLoaderMasks/ResultsData/MeshBuildingMask.h"


namespace meshloader {

class MeshBuildingDataCollector {
public:
    MeshBuildingDataCollector(MeshBuildingMask& meshBuildingMask,
                              NumsMatrix& interiorNumsMatrixP,
                              NumsMatrix& globalNumsMatrixP);

    void createDataStore();
    void fillDataStore();

private:
    MeshBuildingMask& meshBuildingMask_;
    NumsMatrix& interiorNumsMatrixP_; 
    NumsMatrix& globalNumsMatrixP_;

    size_t meshColumns_ = 0;
    size_t meshRows_ = 0;
    size_t activeCells_ = 0;
    size_t gapCells_ = 0;

    size_t getInteriorNum(size_t i, size_t j);
    size_t getGlobalNum(size_t i, size_t j);
};

}
#endif // SIMPLEFVM_MESHLOADER_MESHBUILDINGDATACOLLECTOR_H