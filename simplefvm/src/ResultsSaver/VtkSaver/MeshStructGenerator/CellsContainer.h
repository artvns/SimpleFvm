#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSCONTAINER_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSCONTAINER_H

#include <cstddef>
#include <memory>
#include <vector>

#include "SaverCell.h"


namespace resultssaver {

class CellsContainer {
private:
    using uPtrSaverCell = std::unique_ptr<SaverCell>;
    using uPtrSaverCellVector = std::vector<uPtrSaverCell>;

public:
    CellsContainer();
    
    uPtrSaverCellVector& getContainer();
    uPtrSaverCell& getCell(size_t index);
    size_t getCellsAmount() const;

private:
    uPtrSaverCellVector cellsContainer_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSCONTAINER_H