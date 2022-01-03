#ifndef SIMPLEFVM_MESHLOADER_LOADER_H
#define SIMPLEFVM_MESHLOADER_LOADER_H

#include <cstddef>
#include <string>
#include <vector>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"
#include "MeshLoader/FileReader/ReaderTxt.h"

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/LoaderDataStores/NumsSets.h"
#include "MeshLoader/LoaderDataStores/MeshInformation.h"

#include "MeshLoader/MeshTemplates/TemplateCreator.h"
#include "MeshLoader/CellsNumeration/CellsNumerator.h"
#include "MeshLoader/DomainDecomposition/DomainDecomposer.h"
#include "MeshLoader/MeshContainer/MeshContainerBuilder.h"
#include "MeshLoader/MeshContainer/CellsSizeDefiner.h"
#include "MeshLoader/StaggeredMeshPart/StaggeredMeshModule.h"
#include "MeshLoader/MeshInfoExtraction/MeshInfoExtractor.h"

#include "MeshLoader/FileReader/MeshFileReader.h"
#include "MeshLoader/SolverDataPackers/MainDataPacker.h"
#include "MeshLoader/DataStoresLoaderMasks/DataStoreMasks.h"

#include "MeshLoader/MeshBuildingDataCollector.h"


namespace meshloader {

class Loader {
public:
    Loader(datastores::GlobalDataStores& dataStores);

    void loadDataFromFile(const std::string fileName, 
                            const double dx, const double dy);

private:
    ReaderTxt fileReader_;
    Mesh meshContainer_;
    NumsSets numsSetsP_;
    NumsSets numsSetsU_;
    NumsSets numsSetsV_;

    MeshInformation meshInfoU_;
    MeshInformation meshInfoV_;
    MeshInformation meshInfoP_;

    DataStoreMasks dataStoreMasks_;


    void collectAllBcNames(MeshInformation& meshInfoP, 
                            std::vector<std::string>& bcNamesVector);
};

}
#endif // SIMPLEFVM_MESHLOADER_LOADER_H