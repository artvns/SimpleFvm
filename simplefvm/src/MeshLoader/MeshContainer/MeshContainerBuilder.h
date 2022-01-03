#ifndef SIMPLEFVM_MESHLOADER_MESHCONTAINER_MESHCONTAINERBUILDER_H
#define SIMPLEFVM_MESHLOADER_MESHCONTAINER_MESHCONTAINERBUILDER_H

/*
*   This class creates scattered numbered macrocells and assign
*   dependencies. Then it will put them into the Mesh container from which 
*   it will be possible to get what you need on request.
*/

#include <cstddef>
#include <memory>
#include <vector>

#include "PlatformDependentCode/ConsoleTextColor.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"

#include "Mesh.h"
#include "MacroCell.h"


namespace meshloader {

class MeshContainerBuilder {
private:
    using uPtrMacroCell = std::unique_ptr<MacroCell>;

public:
    MeshContainerBuilder(Mesh& meshContainer, 
                         NumsMatrix& interiorNumsMatrixP, 
                         NumsMatrix& globalNumsMatrixP);

    void buildMesh();

private:
    Mesh& meshContainer_;
    NumsMatrix& interiorNumsMatrixP_;
    NumsMatrix& globalNumsMatrixP_;

    size_t maxLines_ = 0;
    size_t maxCols_  = 0;

    void fillMesh();
    void linkMeshCells();
};

}
#endif // SIMPLEFVM_MESHLOADER_MESHCONTAINER_MESHCONTAINERBUILDER_H