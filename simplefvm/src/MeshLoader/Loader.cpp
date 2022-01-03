#include "Loader.h"

namespace meshloader {

Loader::Loader(
    datastores::GlobalDataStores& dataStores) :
                            dataStoreMasks_(dataStores, 
                                            meshInfoU_, 
                                            meshInfoV_, 
                                            meshInfoP_) {

}

void Loader::loadDataFromFile(const std::string fileName, 
                                        const double dx, const double dy) {

    dataStoreMasks_.getStateFlagsMask().switchMeshLoadingFlagStarted();

    BaseMatrix  baseMatrix_;
    BaseMatrix  templateMatrixP_;
    NumsMatrix  interiorNumsMatrixP_;
    NumsMatrix  globalNumsMatrixP_;


    MeshFileReader meshFileReader_(
        fileReader_, 
        baseMatrix_
    );

    TemplateCreator templateCreator_(
        baseMatrix_, 
        templateMatrixP_
    );

    CellsNumerator cellsNumerator_(
        baseMatrix_, 
        templateMatrixP_,
        interiorNumsMatrixP_,
        globalNumsMatrixP_
    );

    DomainDecomposer domainDecomposer_(
        numsSetsP_,
        baseMatrix_,
        templateMatrixP_,
        interiorNumsMatrixP_
    );

    MeshContainerBuilder meshBuilder_(
        meshContainer_,
        interiorNumsMatrixP_, 
        globalNumsMatrixP_
    );

    StaggeredMeshModule staggMeshModule_(
        meshContainer_, 
        numsSetsP_
    );

    MeshInfoExtractor meshInfoExtractor_;

    ///TODO: this class collects information to build a mesh 
    // for displaying results in post processor. Temp solution, rewrite later.
    MeshBuildingDataCollector meshBuildingDataCollector_(
        dataStoreMasks_.getMeshBuildingMask(),
        interiorNumsMatrixP_,
        globalNumsMatrixP_
    );

    MainDataPacker dataPacker_(
        dataStoreMasks_,
        meshContainer_,
        numsSetsP_,
        numsSetsU_,
        numsSetsV_
    );

    CellsSizeDefiner cellsSizeDefiner_;


    meshFileReader_.readMeshFile(fileName);
    templateCreator_.createTemplate();
    cellsNumerator_.createNumeration();
    domainDecomposer_.decomposeDomain();
    meshBuilder_.buildMesh();
    cellsSizeDefiner_.setCellsSize(meshContainer_, dx, dy);

    staggMeshModule_.createVelocityNumsSets(numsSetsU_, numsSetsV_);

    meshInfoExtractor_.extractInfo(meshInfoU_, numsSetsU_);
    meshInfoExtractor_.extractInfo(meshInfoV_, numsSetsV_);
    meshInfoExtractor_.extractInfo(meshInfoP_, numsSetsP_);

    dataStoreMasks_.createDataMasks();

    meshBuildingDataCollector_.createDataStore();
    meshBuildingDataCollector_.fillDataStore();

    dataPacker_.packData();

    dataStoreMasks_.getStateFlagsMask().switchMeshLoadingFlagAsCompleted();

    collectAllBcNames(meshInfoP_, 
        dataStoreMasks_.getMeshInfoMaskP().getBcNamesVector());
}

void Loader::collectAllBcNames(MeshInformation& meshInfoP, 
                                std::vector<std::string>& bcNamesVector) {

    for (size_t i = 0; i < meshInfoP.getNumberOfParts(); i++) {
        bcNamesVector.push_back(meshInfoP.getFaceName(i));
    }
}

}