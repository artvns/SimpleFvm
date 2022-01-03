#ifndef SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_PARTSCELLSNUMSEXTRACTOR_H
#define SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_PARTSCELLSNUMSEXTRACTOR_H

/*
*   A class that separates the numbers of the constituent parts of the computational domain.
*/

#include <cstddef>
#include <string>
#include <vector>
#include <algorithm>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"

#include "HorizontalFaceNums.h"
#include "VerticalFaceNums.h"
#include "PureInteriorNums.h"


namespace meshloader {

class PartsCellsNumsExtractor {
public:
    PartsCellsNumsExtractor(BaseMatrix& baseMatrix, 
                        BaseMatrix& templateMatrixP,
                        NumsMatrix& interiorNumsMatrixP);

    void extractNumbers();
    std::vector<size_t>& getInteriorNums();
    std::vector<size_t>& getFaceCellsNumsSet(size_t i);

    size_t getNumberOfFaces() const;

    // For debug.
    // void outputFaceNumsSets();
    // void outputInteriorNumsSets();

private:
    std::vector<size_t> interiorNumsSet_;
    std::vector<std::vector<size_t>> facesNumsSets_;
 
    HorizontalFaceNums horizFaces_;
    VerticalFaceNums verticFaces_;
    PureInteriorNums pureInteriorCells_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_PARTSCELLSNUMSEXTRACTOR_H