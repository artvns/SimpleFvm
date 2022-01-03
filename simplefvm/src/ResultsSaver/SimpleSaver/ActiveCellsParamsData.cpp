#include "ActiveCellsParamsData.h"

namespace resultssaver {

ActiveCellsParamsData::ActiveCellsParamsData(
                    datastores::FieldsStore& fields, 
                    datastores::MeshParametersStore& meshParams, 
                    datastores::MeshBuildingStore& meshBuilding) :
                                    fields_(fields),
                                    meshParams_(meshParams),
                                    meshBuilding_(meshBuilding) {

}

void ActiveCellsParamsData::outputData(std::ofstream& fout) {
    fout << "Cell№\t\tiPos\t\tjPos\t\tdx\t\tdy\t\tu\t\tv\t\tp" << '\n';

    for (size_t i = 0; i < meshBuilding_.getActiveCellsAmount(); i++) {

        fout << meshBuilding_.getActiveCellNum().getValue(i) << "\t\t";
        fout << meshBuilding_.getActiveCell_iPos().getValue(i) << "\t\t";
        fout << meshBuilding_.getActiveCell_jPos().getValue(i) << "\t\t";

        size_t numPos = meshBuilding_.getActiveCellNum().getValue(i) - 1;

        fout << meshParams_.get_dX().getValue(numPos) << "\t\t";
        fout << meshParams_.get_dY().getValue(numPos) << "\t\t";

        fout << fields_.get_uCellCentered().getValue(numPos) << "\t\t";
        fout << fields_.get_vCellCentered().getValue(numPos) << "\t\t";
        fout << fields_.get_p().getValue(numPos) << "\n";
    }
}

}