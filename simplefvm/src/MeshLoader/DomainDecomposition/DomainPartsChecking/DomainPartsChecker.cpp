#include "DomainPartsChecker.h"

namespace meshloader {

DomainPartsChecker::DomainPartsChecker() {

}

void DomainPartsChecker::checkPart(const std::vector<char>& extractedPartName,
                                    const std::vector<char>& partCellsNames) {
    checkPartName(extractedPartName);
    checkPartCellsAmount(partCellsNames.size(), extractedPartName);
}

void DomainPartsChecker::checkPartName(const std::vector<char>& vec) {
    if (vec.size() > 1) {
        std::vector<char> b_(vec);

        throw customexceptions::DomainPartsException(
                "Some part has more than one name:",
                b_);
    }
}

void DomainPartsChecker::checkPartCellsAmount(const size_t partCellsAmount, 
                                                const std::vector<char>& vec) {

    if (partCellsAmount < exeptableAmountOfPartCells_) {

        std::vector<char> b_(vec);

        throw customexceptions::DomainPartsException(
                "The amount of cells is not enough in domain parts:",
                b_);
    }
}

}