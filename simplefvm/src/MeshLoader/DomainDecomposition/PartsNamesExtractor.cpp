#include "PartsNamesExtractor.h"

namespace meshloader {

PartsNamesExtractor::PartsNamesExtractor() {

}

char PartsNamesExtractor::extractName(std::vector<size_t>& numsSet, 
        const BaseMatrix& baseMatrix, const NumsMatrix& interiorNumsMatrixP) {

    char partName;
    size_t maxLines_ = baseMatrix.getRowsAmount();
    size_t maxCols_ = baseMatrix.getColsAmount();

    std::vector<char> partCellsNames_;                                          // Vector of names of all grid cells.

    for (size_t k = 0; k < numsSet.size(); k++) {
        
        for (size_t i = 0; i < maxLines_; i++) {
            for (size_t j = 0; j < maxCols_; j++) {
                if (numsSet.at(k) == interiorNumsMatrixP.getValue(i + 1, j + 1)) {
                    partCellsNames_.push_back(baseMatrix.getValue(i, j));
                }
            }
        }
    }


    std::vector<char> allExtractedPartNames_;

    for (size_t i = 0; i < partCellsNames_.size(); i++) {
        if ('x' != partCellsNames_.at(i)) {
            allExtractedPartNames_.push_back(partCellsNames_.at(i));
        }
    }

    domainPartsChecker_.checkPart(allExtractedPartNames_, partCellsNames_);

    partName = allExtractedPartNames_.at(0);

    return partName;
}

}