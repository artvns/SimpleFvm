#include "MeshInformation.h"

namespace resultssaver {

MeshInformation::MeshInformation(
    datastores::MeshParametersStore& meshParams, 
    datastores::MeshBuildingStore& meshBuilding) : 
                            meshParams_(meshParams),
                            meshBuilding_(meshBuilding) {

}

size_t MeshInformation::getCellsAmount() const {
    return meshBuilding_.getActiveCellsAmount();
}

size_t MeshInformation::getDimentionX() const {
    return meshBuilding_.getMeshSizeX();
}

size_t MeshInformation::getDimentionY() const {
    return meshBuilding_.getMeshSizeY();
}

size_t MeshInformation::getCellNum(size_t index) const {
    return meshBuilding_.getActiveCellNum().getValue(index);
}

size_t MeshInformation::getCell_iPos(size_t index) const {
    return meshBuilding_.getActiveCell_iPos().getValue(index);
}

size_t MeshInformation::getCell_jPos(size_t index) const {
    return meshBuilding_.getActiveCell_jPos().getValue(index); 
}

///TODO: all cells still are the same size. rewrite later.
double MeshInformation::get_dX() const {
    return meshParams_.get_dX().getValue(0);
}

double MeshInformation::get_dY() const {
    return meshParams_.get_dY().getValue(0);
}

}