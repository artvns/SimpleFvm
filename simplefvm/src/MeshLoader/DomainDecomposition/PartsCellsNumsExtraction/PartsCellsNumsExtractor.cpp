#include "PartsCellsNumsExtractor.h"

namespace meshloader {

PartsCellsNumsExtractor::PartsCellsNumsExtractor(
        BaseMatrix& baseMatrix,
        BaseMatrix& templateMatrixP,
        NumsMatrix& interiorNumsMatrixP) :
                        horizFaces_(baseMatrix, 
                                    templateMatrixP, 
                                    interiorNumsMatrixP, 
                                    facesNumsSets_),
                        verticFaces_(baseMatrix,
                                     templateMatrixP, 
                                     interiorNumsMatrixP, 
                                     facesNumsSets_),
                        pureInteriorCells_(baseMatrix, 
                                           templateMatrixP, 
                                           interiorNumsMatrixP) {

}

void PartsCellsNumsExtractor::extractNumbers() {
    horizFaces_.findNums();
    verticFaces_.findNums();
    pureInteriorCells_.findNums(interiorNumsSet_, facesNumsSets_);
}

std::vector<size_t>& PartsCellsNumsExtractor::getInteriorNums() {
    return interiorNumsSet_;
}

std::vector<size_t>& PartsCellsNumsExtractor::getFaceCellsNumsSet(size_t i) {
    return facesNumsSets_.at(i);
}

size_t PartsCellsNumsExtractor::getNumberOfFaces() const {
    return facesNumsSets_.size();
}

}