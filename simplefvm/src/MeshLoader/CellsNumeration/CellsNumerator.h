#ifndef SIMPLEFVM_MESHLOADER_CELLSNUMERATION_CELLSNUMERATOR_H
#define SIMPLEFVM_MESHLOADER_CELLSNUMERATION_CELLSNUMERATOR_H

#include <string>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"

#include "InteriorCellsNumerator.h"
#include "GlobalCellsNumerator.h"


namespace meshloader {

class CellsNumerator {
public:
    CellsNumerator(BaseMatrix& baseMatrix_, 
                   BaseMatrix& templateMatrixP,
                   NumsMatrix& interiorNumsMatrixP, 
                   NumsMatrix& globalNumsMatrixP);

    void createNumeration();

private:
    BaseMatrix& baseMatrix_;
    BaseMatrix& templateMatrixP_;
    NumsMatrix& interiorNumsMatrixP_; 
    NumsMatrix& globalNumsMatrixP_;

    InteriorCellsNumerator interiorCellsNumeratorP_;
    GlobalCellsNumerator globalCellsNumeratorP_;
};

}
#endif // SIMPLEFVM_MESHLOADER_CELLSNUMERATION_CELLSNUMERATOR_H