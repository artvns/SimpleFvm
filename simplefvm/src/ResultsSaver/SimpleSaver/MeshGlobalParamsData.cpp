#include "MeshGlobalParamsData.h"

namespace resultssaver {

MeshGlobalParamsData::MeshGlobalParamsData(
    datastores::MeshBuildingStore& meshBuilding) :
                                meshBuilding_(meshBuilding) {

}

void MeshGlobalParamsData::outputData(std::ofstream& fout) {
    fout << "cellsAmount:\t" << meshBuilding_.getActiveCellsAmount() << '\n';
    fout << "gapCellsAmount:\t" << meshBuilding_.getGapCellsAmount() << '\n';
    fout << "mesh_size_x:\t" << meshBuilding_.getMeshSizeX() << '\n';
    fout << "mesh_size_y:\t" << meshBuilding_.getMeshSizeY() << '\n';
}

}