#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSGENERATOR_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSGENERATOR_H

#include <cstddef>
#include <memory>
#include <vector>

#include "../RecievedData/MeshInformation.h"

#include "SaverCell.h"
#include "SaverPoint.h"
#include "CellsContainer.h"
#include "PointsContainer.h"
#include "CellsInfo.h"


namespace resultssaver {

class CellsGenerator {
private:
    using uPtrSaverCell = std::unique_ptr<SaverCell>;
    using uPtrSaverPoint = std::unique_ptr<SaverPoint>;

public:
    CellsGenerator();

    void createCellsAndPoints(const MeshInformation& meshData,
                                const CellsInfo& cellsInfo, 
                                std::vector<uPtrSaverPoint>& points,
                                std::vector<uPtrSaverCell>& cells);

private:

};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSGENERATOR_H