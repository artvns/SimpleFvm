#include "AbstractValuePacker.h"

namespace resultssaver {

AbstractValuePacker::AbstractValuePacker(
            const RecievedCellData& recievedData,
            const MeshInformation& meshInfo) : 
                    cellsAmount_(meshInfo.getCellsAmount()),
                    recievedData_(recievedData) {

}

AbstractValuePacker::~AbstractValuePacker() {
    
}

vtkNew<vtkDoubleArray>& AbstractValuePacker::getCellValues() {
    return cellValues_;
}

}