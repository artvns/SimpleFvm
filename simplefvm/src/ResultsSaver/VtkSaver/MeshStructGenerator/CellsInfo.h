#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSINFO_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSINFO_H

#include <cstddef>
#include <vector>
#include <iostream>

#include "../RecievedData/MeshInformation.h"


namespace resultssaver {

class CellsInfo {
public:
    CellsInfo(MeshInformation& meshInfo);

    void createTemplates();

    size_t getType(size_t i, size_t j) const;
    size_t getNum(size_t i, size_t j) const;

private:
    MeshInformation& meshInfo_; 

    std::vector<std::vector<size_t>> cellTypes_;
    std::vector<std::vector<size_t>> cellNums_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_CELLSINFO_H