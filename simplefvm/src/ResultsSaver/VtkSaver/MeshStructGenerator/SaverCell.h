#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_SAVERCELL_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_SAVERCELL_H

#include <cstddef>


namespace resultssaver {

class SaverCell {
public:
    SaverCell(size_t cellNum, size_t pointId_0, size_t pointId_1, 
            size_t pointId_2, size_t pointId_3);

    void setAdjCellNumW(size_t cellNum);
    void setAdjCellNumS(size_t cellNum);

    size_t getAdjCellW() const;
    size_t getAdjCellS() const;

    size_t getNum() const;

    size_t getPointId_0() const;
    size_t getPointId_1() const;
    size_t getPointId_2() const;
    size_t getPointId_3() const;

private:
    size_t cellNum_ = 0;
    size_t pointNum0_ = 0;
    size_t pointNum1_ = 0;
    size_t pointNum2_ = 0;
    size_t pointNum3_ = 0;

    size_t adjCellNumW_ = 0;
    size_t adjCellNumS_ = 0;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_SAVERCELL_H