#include "MeshParamsPacker.h"

namespace meshloader {

MeshParamsPacker::MeshParamsPacker(
                    DataStoreMasks& dataContainer, 
                    Mesh& mesh) :
                            dataContainer_(dataContainer),
                            mesh_(mesh) {

}

void MeshParamsPacker::packMeshParameters() {
    size_t allCellsAmount_ = mesh_.getCellsAmount();

    createStores(allCellsAmount_);

    for (size_t i = 0; i < allCellsAmount_; i++) {
        size_t num_ = mesh_.getCellByIndex(i)->getCellGlobalNum();
        packMeshValuesP(i, num_);
        packMeshValuesU(i, num_);
        packMeshValuesV(i, num_);
    }
}

void MeshParamsPacker::packMeshValuesP(size_t idx, size_t cellNum) {
    size_t numAsIndex_ = cellNum - 1;

    dataContainer_.getMeshParametersMaskP().set_dX(
        numAsIndex_, 
        mesh_.getCellByIndex(idx)->getCellP().get_dX()
    );

    dataContainer_.getMeshParametersMaskP().set_dY(
        numAsIndex_, 
        mesh_.getCellByIndex(idx)->getCellP().get_dY()
    );
}

void MeshParamsPacker::packMeshValuesU(size_t idx, size_t cellNum) {
    size_t numAsIndex_ = cellNum - 1;

    dataContainer_.getMeshParametersMaskU().set_dX(
        numAsIndex_, 
        mesh_.getCellByIndex(idx)->getCellU().get_dX()
    );

    dataContainer_.getMeshParametersMaskU().set_dY(
        numAsIndex_, 
        mesh_.getCellByIndex(idx)->getCellU().get_dY()
    );
}

void MeshParamsPacker::packMeshValuesV(size_t idx, size_t cellNum) {
    size_t numAsIndex_ = cellNum - 1;

    dataContainer_.getMeshParametersMaskV().set_dX(
        numAsIndex_, 
        mesh_.getCellByIndex(idx)->getCellV().get_dX()
    );
    
    dataContainer_.getMeshParametersMaskV().set_dY(
        numAsIndex_, 
        mesh_.getCellByIndex(idx)->getCellV().get_dY()
    );
}

void MeshParamsPacker::createStores(size_t storeSize) {
    dataContainer_.getMeshParametersMaskP().createStore(storeSize);
    dataContainer_.getMeshParametersMaskU().createStore(storeSize);
    dataContainer_.getMeshParametersMaskV().createStore(storeSize);
}

}