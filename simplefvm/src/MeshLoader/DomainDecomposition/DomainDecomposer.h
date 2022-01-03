#ifndef SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_DOMAINDECOMPOSER_H
#define SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_DOMAINDECOMPOSER_H

/*
*   A class that decomposes the original mesh into sets 
*   of cell numbers for domain elements.
*/

#include <cstddef>

#include "MeshLoader/LoaderDataStores/NumsSets.h"
#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"

#include "PartsNamesExtractor.h"
#include "./PartsCellsNumsExtraction/PartsCellsNumsExtractor.h"


namespace meshloader {

class DomainDecomposer {
public:
    DomainDecomposer(NumsSets& numsSets,
                    BaseMatrix& baseMatrix,
                    BaseMatrix& templateMatrixP,
                    NumsMatrix& interiorNumsMatrixP);

    void decomposeDomain();

private:
    NumsSets&   numsSets_;
    BaseMatrix& baseMatrix_;
    BaseMatrix& templateMatrixP_;
    NumsMatrix& interiorNumsMatrixP_;

    PartsCellsNumsExtractor partNumsExtractor_;
    PartsNamesExtractor partsNamesExtractor_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_DOMAINDECOMPOSER_H