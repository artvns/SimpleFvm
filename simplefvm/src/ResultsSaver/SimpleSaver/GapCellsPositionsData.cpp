#include "GapCellsPositionsData.h"

namespace resultssaver {

GapCellsPositionsData::GapCellsPositionsData(
    datastores::MeshParametersStore& meshParams, 
    datastores::MeshBuildingStore& meshBuilding) :
                                    meshParams_(meshParams),
                                    meshBuilding_(meshBuilding) {

}

void GapCellsPositionsData::outputData(std::ofstream& fout) {
    fout << "№\t\tiPos\t\tjPos" << '\n';

    for (size_t i = 0; i < meshBuilding_.getGapCellsAmount(); i++) {
        fout << meshBuilding_.getGapCellNum().getValue(i) << "\t\t";
        fout << meshBuilding_.getGapCell_iPos().getValue(i) << "\t\t";
        fout << meshBuilding_.getGapCell_jPos().getValue(i) << "\n";
    }
}

}