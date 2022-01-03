#include "Saver.h"

namespace resultssaver {

Saver::Saver(
            datastores::FieldsStore& fields, 
            datastores::MeshParametersStore& meshParams, 
            datastores::MeshBuildingStore& meshBuilding) :
                            fields_(fields),
                            meshParams_(meshParams),
                            meshBuilding_(meshBuilding) {

}

void Saver::saveDataVtk(const std::string fileName) {
    VtkDataSaver dataSaver_(
            fields_, 
            meshParams_, 
            meshBuilding_
    );
    dataSaver_.saveData(fileName);
}

void Saver::saveDataTxt(const std::string fileName) {
    SimpleDataSaver dataSaver_(
            fields_, 
            meshParams_, 
            meshBuilding_
    );
    dataSaver_.saveData(fileName);
}

}