#ifndef SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_PUREINTERIORNUMS_H
#define SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_PUREINTERIORNUMS_H

#include <cstddef>
#include <string>
#include <vector>
#include <algorithm>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"
#include "MeshLoader/LoaderDataStores/NumsMatrix.h"


namespace meshloader {

class PureInteriorNums {
public:
    PureInteriorNums(BaseMatrix& baseMatrix, 
                        BaseMatrix& templateMatrixP,
                        NumsMatrix& interiorNumsMatrixP);

    void findNums(std::vector<size_t>& interiorNumsSet,
                    const std::vector<std::vector<size_t>>& facesNumsSets);

private:
    BaseMatrix& baseMatrix_;
    BaseMatrix& templateMatrixP_;
    NumsMatrix& interiorNumsMatrixP_;

    std::vector<size_t> facesNums_;

    size_t takeNumber(size_t i, size_t j);
    
    bool isCell(size_t i, size_t j);
    bool isFaceNum(const size_t num);

    void sortVector(std::vector<size_t>& v);
    void removeDuplicatedValues(std::vector<size_t>& v);

    void uniteFacesNums(const std::vector<std::vector<size_t>>& nums);
};

}
#endif // SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_PARTSCELLSNUMSEXTRACTION_PUREINTERIORNUMS_H