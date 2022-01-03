#ifndef SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_HORIZONTALFACENUMS_H
#define SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_HORIZONTALFACENUMS_H

#include <cstddef>
#include <string>
#include <vector>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"


namespace meshloader {

class HorizontalFaceNums {
public:
    HorizontalFaceNums(BaseMatrix& baseMatrix, 
                        BaseMatrix& templateMatrixP,
                        NumsMatrix& interiorNumsMatrixP,
                        std::vector<std::vector<size_t>>& numsSets);

    void findNums();

private:
    BaseMatrix& baseMatrix_;
    BaseMatrix& templateMatrixP_;
    NumsMatrix& interiorNumsMatrixP_;

    std::vector<std::vector<size_t>>& allNums_;

    std::vector<size_t> oneTopFaceNums_;
    std::vector<size_t> oneBottomFaceNums_;
    std::vector<std::vector<size_t>> allTopNums_;
    std::vector<std::vector<size_t>> allBottomNums_;


    size_t takeNumber(size_t i, size_t j);

    void checkTopSide(size_t i,  size_t maxCols);
    void checkBottomSide(size_t i, size_t maxCols);

    bool isCell(size_t i, size_t j);                            // Checking if this cell is not empty.
    bool isTopSide(size_t i, size_t j);
    bool isBottomSide(size_t i, size_t j);

    bool isTopFaceFinish(size_t i, size_t j);
    bool isBottomFaceFinish(size_t i, size_t j);

    void uniteTopBottomSets();
};

}
#endif // SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_HORIZONTALFACENUMS_H