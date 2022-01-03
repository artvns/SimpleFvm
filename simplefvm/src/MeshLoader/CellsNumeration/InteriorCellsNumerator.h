#ifndef SIMPLEFVM_MESHLOADER_CELLSNUMERATION_INTERIORCELLSNUMERATOR_H
#define SIMPLEFVM_MESHLOADER_CELLSNUMERATION_INTERIORCELLSNUMERATOR_H

#include <cstddef>
#include <string>
#include <new>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"


namespace meshloader {

class InteriorCellsNumerator {
public:
    InteriorCellsNumerator(BaseMatrix& templateMatrixP, 
                           NumsMatrix& interiorNumsMatrixP);

    void numerateCells();
    size_t getLatestCellNum();

private:
    BaseMatrix& templateMatrixP_;
    NumsMatrix& interiorNumsMatrixP_;

    size_t maxLines_ = 0;
    size_t maxColumns_ = 0;
    size_t latestCellNum_ = 0;

    void createMatrix();
};

}
#endif // SIMPLEFVM_MESHLOADER_CELLSNUMERATION_INTERIORCELLSNUMERATOR_H