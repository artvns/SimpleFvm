#ifndef SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_VERTICALFACENUMS_H
#define SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_VERTICALFACENUMS_H

#include <cstddef>
#include <string>
#include <vector>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"


namespace meshloader {

class VerticalFaceNums {
public:
    VerticalFaceNums(BaseMatrix& baseMatrix, 
                        BaseMatrix& templateMatrixP,
                        NumsMatrix& interiorNumsMatrixP,
                        std::vector<std::vector<size_t>>& numsSets);

    void findNums();

private:
    BaseMatrix& baseMatrix_;
    BaseMatrix& templateMatrixP_;
    NumsMatrix& interiorNumsMatrixP_;
    
    std::vector<std::vector<size_t>>& allNums_;

    std::vector<size_t> oneLeftFaceNums_;
    std::vector<size_t> oneRightFaceNums_;
    std::vector<std::vector<size_t>> allLeftNums_;
    std::vector<std::vector<size_t>> allRightNums_;


    size_t takeNumber(size_t i, size_t j);

    void checkLeftSide(size_t j,  size_t maxLines);
    void checkRightSide(size_t j, size_t maxLines);

    bool isCell(size_t i, size_t j);                            // Checking if this cell is not empty.
    bool isLeftSide(size_t i, size_t j);
    bool isRightSide(size_t i, size_t j);

    bool isLeftFaceFinish(size_t i, size_t j);
    bool isRightFaceFinish(size_t i, size_t j);

    void uniteLeftRightSets();

    // Done to prevent duplicate cell numbers on surfaces.
    ///TODO: change later.
    bool isHorizFaceNum(size_t i, size_t j);
};

}
#endif // SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_VERTICALFACENUMS_H