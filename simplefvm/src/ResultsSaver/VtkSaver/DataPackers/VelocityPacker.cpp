#include "VelocityPacker.h"

namespace resultssaver {

VelocityPacker::VelocityPacker(
            const RecievedCellData& recievedData, 
            const MeshInformation& meshInfo) : 
                        AbstractValuePacker(recievedData, meshInfo) {

}

void VelocityPacker::packSaverCellValues() {
    cellValues_->SetName("velocity");
    cellValues_->SetNumberOfComponents(3);
    cellValues_->SetNumberOfTuples(cellsAmount_);

    for (size_t i = 0; i < cellsAmount_; i++) {
        cellValues_->SetTuple3(
            i, 
            recievedData_.getUVelValue(i), 
            recievedData_.getVVelValue(i), 
            0.0);
    }
}

}