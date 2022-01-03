#include "CellsInfo.h"

namespace resultssaver {

CellsInfo::CellsInfo(MeshInformation& meshInfo) : 
                                    meshInfo_(meshInfo) {

}

void CellsInfo::createTemplates() {

    size_t iSize_ = meshInfo_.getDimentionY();  
    size_t jSize_ = meshInfo_.getDimentionX();

    size_t iSizeExt_ = iSize_ + 2;  
    size_t jSizeExt_ = jSize_ + 2;

    cellTypes_.resize(iSizeExt_);
    for (size_t i = 0; i < iSizeExt_; i++) {
        cellTypes_.at(i) = std::vector<size_t>(jSizeExt_, 0);
    }

    cellNums_.resize(iSize_);
    for (size_t i = 0; i < iSize_; i++) {
        cellNums_.at(i) = std::vector<size_t>(jSize_, 0);
    }


    for (size_t i = 0; i < meshInfo_.getCellsAmount(); i++) {
        size_t iPos_modyfied_ = meshInfo_.getCell_iPos(i);
        size_t jPos_ = meshInfo_.getCell_jPos(i);

        cellTypes_[iPos_modyfied_ + 1][jPos_ + 1] = 1;
        cellNums_[iPos_modyfied_][jPos_] = meshInfo_.getCellNum(i) - 1;
    }
}

size_t CellsInfo::getType(size_t i, size_t j) const {
    return cellTypes_[i][j];
}

size_t CellsInfo::getNum(size_t i, size_t j) const {
    return cellNums_[i][j];
}

}