#include "DataPacker.h"

namespace resultssaver {

DataPacker::DataPacker(DataMasks& dataMasks) : 
        pressurePacker_(dataMasks.getRecievedCellData(),
                            dataMasks.getMeshInformation()),
        velocityPacker_(dataMasks.getRecievedCellData(),
                            dataMasks.getMeshInformation()) {

}

void DataPacker::packData() {
    pressurePacker_.packSaverCellValues();
    velocityPacker_.packSaverCellValues();
}

vtkNew<vtkDoubleArray>& DataPacker::getPressure() {
    return pressurePacker_.getCellValues();
}

vtkNew<vtkDoubleArray>& DataPacker::getVelocity() {
    return velocityPacker_.getCellValues();
}

}