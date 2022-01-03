#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_VTKDATASAVER_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_VTKDATASAVER_H

#include <cstddef>

#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkPolyDataWriter.h>
#include <vtkPolygon.h>
#include <vtkQuad.h>
#include <vtkCellArray.h>

#include "DataStores/FieldsStores/FieldsStore.h"
#include "DataStores/MeshParametersStores/MeshParametersStore.h"
#include "DataStores/ResultsDataStores/MeshBuildingStore.h"

#include "../IResultsSaver.h"
#include "DataPackers/DataPacker.h"
#include "MeshStructGenerator/CellsGenerator.h"
#include "MeshStructGenerator/CellsContainer.h"
#include "MeshStructGenerator/PointsContainer.h"
#include "MeshStructGenerator/CellsInfo.h"
#include "RecievedData/DataMasks.h"


namespace resultssaver {

class VtkDataSaver : public IResultsSaver {
public:
    VtkDataSaver(datastores::FieldsStore& fields, 
                datastores::MeshParametersStore& meshParams, 
                datastores::MeshBuildingStore& meshBuilding);

    void saveData(const std::string fileName) override;

private:
    DataMasks dataMasks_;
    const std::string fileName_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_VTKDATASAVER_H