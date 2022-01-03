#ifndef SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_DOMAINPARTSCHECKING_DOMAINPARTSCHECKER_H
#define SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_DOMAINPARTSCHECKING_DOMAINPARTSCHECKER_H

#include <cstddef>
#include <vector>

#include "CustomExceptions/DomainPartsException.h"


namespace meshloader {

class DomainPartsChecker {
public:
    DomainPartsChecker();

    void checkPart(const std::vector<char>& extractedPartName,
                        const std::vector<char>& partCellsNames);

private:
    const size_t exeptableAmountOfPartCells_ = 3;

    void checkPartName(const std::vector<char>& vec);
    void checkPartCellsAmount(const size_t partCellsAmount, 
                                const std::vector<char>& vec);
};

}
#endif // SIMPLEFVM_MESHLOADER_DOMAINDECOMPOSITION_DOMAINPARTSCHECKING_DOMAINPARTSCHECKER_H