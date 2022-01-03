#ifndef SIMPLEFVM_MESHLOADER_CELLSNUMERATION_GLOBALCELLSNUMERATOR_H
#define SIMPLEFVM_MESHLOADER_CELLSNUMERATION_GLOBALCELLSNUMERATOR_H

#include <cstddef>
#include <string>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"

#include "InteriorCellsNumerator.h"


namespace meshloader {

class GlobalCellsNumerator {
public:
    GlobalCellsNumerator(BaseMatrix& baseMatrix, 
                         BaseMatrix& templateMatrixP, 
                         NumsMatrix& interiorNumsMatrixP, 
                         NumsMatrix& globalNumsMatrixP);

    void numerateCells(size_t maxInteriorCellNum);

private:
    BaseMatrix& baseMatrix_;
    BaseMatrix& templateMatrixP_;
    NumsMatrix& interiorNumsMatrixP_;
    NumsMatrix& globalNumsMatrixP_;

    size_t maxLines_  = 0;
    size_t maxColumns_ = 0;

    void createMatrix();
    void insertInteriorNums();
};

}
#endif // SIMPLEFVM_MESHLOADER_CELLSNUMERATION_GLOBALCELLSNUMERATOR_H