#include "PressurePacker.h"

namespace resultssaver {

PressurePacker::PressurePacker(
            const RecievedCellData& recievedData, 
            const MeshInformation& meshInfo) : 
                        AbstractValuePacker(recievedData, meshInfo) {

}

void PressurePacker::packSaverCellValues() {
    cellValues_->SetName("pressure");
    cellValues_->SetNumberOfTuples(cellsAmount_);

    for (size_t i = 0; i < cellsAmount_; ++i) {
        cellValues_->SetValue(i, recievedData_.getPressValue(i));
    }
}

}