#ifndef SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSNAMESEXTRACTOR_H
#define SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSNAMESEXTRACTOR_H

#include <cstddef>
#include <string>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"

#include "DomainPartsChecking/DomainPartsChecker.h"


namespace meshloader {

class PartsNamesExtractor {
public:
    PartsNamesExtractor();

    char extractName(std::vector<size_t>& numsSet, 
        const BaseMatrix& baseMatrix, const NumsMatrix& interiorNumsMatrixP);

private:
    DomainPartsChecker domainPartsChecker_;
 
};

}
#endif // SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSNAMESEXTRACTOR_H