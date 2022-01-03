#include "SimpleDataSaver.h"

namespace resultssaver {

SimpleDataSaver::SimpleDataSaver(
    datastores::FieldsStore& fields, 
    datastores::MeshParametersStore& meshParams, 
    datastores::MeshBuildingStore& meshBuilding) :
                    meshGlobalParams_(meshBuilding),
                    activeCellsParams_(fields, meshParams, meshBuilding),
                    gapCellsPositions_(meshParams, meshBuilding) {

}

void SimpleDataSaver::saveData(const std::string fileName) {
    std::string fileName_(fileName);
    fileName_.append(".txt");
    std::ofstream fout(fileName_);

    fout << "<--- Header --->" << std::endl;
    fileHeader_.outputData(fout);

    fout << std::endl;
    fout << std::endl;
    fout << "<--- Mesh_Global_Parameters --->" << std::endl;
    meshGlobalParams_.outputData(fout);

    fout << std::endl;
    fout << std::endl;
    fout << "<--- Active_Cells_Parameters --->" << std::endl;
    activeCellsParams_.outputData(fout);

    fout << std::endl;
    fout << std::endl;
    fout << "<--- Gap_Cells_Positions --->" << std::endl;
    gapCellsPositions_.outputData(fout);

    fout.close();
}

}