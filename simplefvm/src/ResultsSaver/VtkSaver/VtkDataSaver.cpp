#include "VtkDataSaver.h"

namespace resultssaver {

VtkDataSaver::VtkDataSaver(
    datastores::FieldsStore& fields, 
    datastores::MeshParametersStore& meshParams, 
    datastores::MeshBuildingStore& meshBuilding) :
                        dataMasks_(fields, meshParams, meshBuilding) {

}

void VtkDataSaver::saveData(const std::string fileName) {
    std::string fileName_(fileName);
    fileName_.append(".vtk");

    vtkNew<vtkPoints> points_;
    vtkNew<vtkCellArray> quads_;
    vtkNew<vtkQuad> quad_;


    PointsContainer pointsContainer_;
    CellsContainer cellsContainer_;

    CellsInfo cellsInfo_(dataMasks_.getMeshInformation());
    cellsInfo_.createTemplates();

    CellsGenerator cellsGenerator_;
    cellsGenerator_.createCellsAndPoints(
        dataMasks_.getMeshInformation(),
        cellsInfo_,
        pointsContainer_.getContainer(),
        cellsContainer_.getContainer()
    );


    for (size_t i = 0; i < pointsContainer_.getPointsAmount(); i++) {
        points_->InsertNextPoint(
            pointsContainer_.getPoint(i)->getCoordX(),
            pointsContainer_.getPoint(i)->getCoordY(),
            0.0);

    }

    for (size_t i = 0; i < cellsContainer_.getCellsAmount(); i++) {
        quad_->GetPointIds()->SetId(0, cellsContainer_.getCell(i)->getPointId_0());
        quad_->GetPointIds()->SetId(1, cellsContainer_.getCell(i)->getPointId_1());
        quad_->GetPointIds()->SetId(2, cellsContainer_.getCell(i)->getPointId_2());
        quad_->GetPointIds()->SetId(3, cellsContainer_.getCell(i)->getPointId_3());
        quads_->InsertNextCell(quad_);
    }


    // Create a PolyData
    vtkNew<vtkPolyData> polyData_;
    polyData_->SetPoints(points_);
    polyData_->SetPolys(quads_);


    DataPacker dataPacker_(dataMasks_);
    dataPacker_.packData();


    polyData_->GetCellData()->SetScalars(dataPacker_.getPressure());
    polyData_->GetCellData()->SetVectors(dataPacker_.getVelocity());

    vtkNew<vtkPolyDataWriter> writer;
    writer->SetFileName(fileName_.c_str());
    writer->SetInputData(polyData_);
    writer->Write();
}

}