#include "DomainDecomposer.h"

namespace meshloader {

DomainDecomposer::DomainDecomposer(
            NumsSets& numsSets,
            BaseMatrix& baseMatrix,
            BaseMatrix& templateMatrixP,
            NumsMatrix& interiorNumsMatrixP) :
                        numsSets_(numsSets),
                        baseMatrix_(baseMatrix),
                        templateMatrixP_(templateMatrixP),
                        interiorNumsMatrixP_(interiorNumsMatrixP),
                        partNumsExtractor_( baseMatrix, 
                                        templateMatrixP, 
                                        interiorNumsMatrixP) {

}

void DomainDecomposer::decomposeDomain() {
    partNumsExtractor_.extractNumbers();

    // Writing numbers of interior cells.
    char interiorCellsName_ = 'z';                                                      // Name of interior cells (temp solution).
    numsSets_.addNumsSet(interiorCellsName_, partNumsExtractor_.getInteriorNums());

    // Writing numbers of cells adjacent to surfaces.
    for (size_t i = 0; i < partNumsExtractor_.getNumberOfFaces(); i++) {
        char name = partsNamesExtractor_.extractName(
            partNumsExtractor_.getFaceCellsNumsSet(i),
            baseMatrix_,
            interiorNumsMatrixP_
        );

        numsSets_.addNumsSet(name, partNumsExtractor_.getFaceCellsNumsSet(i));
    }
}

}