#include "SaverCell.h"

namespace resultssaver {

SaverCell::SaverCell(
        size_t cellNum, 
        size_t pointId_0, 
        size_t pointId_1, 
        size_t pointId_2, 
        size_t pointId_3) : 
                    cellNum_(cellNum),
                    pointNum0_(pointId_0),
                    pointNum1_(pointId_1),
                    pointNum2_(pointId_2),
                    pointNum3_(pointId_3) {

}

void SaverCell::setAdjCellNumW(size_t cellNum) {
    adjCellNumW_ = cellNum;
}

void SaverCell::setAdjCellNumS(size_t cellNum) {
    adjCellNumS_ = cellNum;
}

size_t SaverCell::getAdjCellW() const {
    return adjCellNumW_;
}

size_t SaverCell::getAdjCellS() const {
    return adjCellNumS_;
}

size_t SaverCell::getNum() const {
    return cellNum_;
}

size_t SaverCell::getPointId_0() const {
    return pointNum0_;
}

size_t SaverCell::getPointId_1() const {
    return pointNum1_;
}

size_t SaverCell::getPointId_2() const {
    return pointNum2_;
}

size_t SaverCell::getPointId_3() const {
    return pointNum3_;
}

}