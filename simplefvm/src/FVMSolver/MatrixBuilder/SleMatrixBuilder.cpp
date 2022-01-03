#include "SleMatrixBuilder.h"

namespace fvmsolver {

SleMatrixBuilder::SleMatrixBuilder(
                AbstractCoeffsCalculator& coeffsCalculator, 
                uPtrDataPort spData) :
                                spDataPort_(std::move(spData)),
                                dataPort_(*spDataPort_),
                                coeffsCalculator_(coeffsCalculator),
                                aP_(dataPort_.getAp()),
                                aW_(dataPort_.getAw()),
                                aE_(dataPort_.getAe()),
                                aN_(dataPort_.getAn()),
                                aS_(dataPort_.getAs()) {

}

void SleMatrixBuilder::build(std::shared_ptr<SleSolver> sleSolver) {
    pSleSolver_ = sleSolver;

    createMatrixAndVectors();
    buildInterior();
    buildBoundary();
}

void SleMatrixBuilder::buildInterior() {
    size_t domainParts = dataPort_.getInteriorPartsAmount();

    for (size_t partId = 0; partId < domainParts; partId++) {
        std::string name = dataPort_.getInteriorName(partId);

        coeffsCalculator_.chooseActualDomainPart(name);

        size_t partCells = dataPort_.getPartCellsAmount(name);
        for (size_t i = 0; i < partCells; i++) {
            coeffsCalculator_.calculateInterior(i);
            placeAllCoeffs();
        }
    }
}

void SleMatrixBuilder::buildBoundary() {
size_t domainParts = dataPort_.getBcPartsAmount();

    for (size_t partId = 0; partId < domainParts; partId++) {
        std::string name = dataPort_.getBoundaryName(partId);

        coeffsCalculator_.chooseActualDomainPart(name);

        size_t partCells = dataPort_.getPartCellsAmount(name);
        for (size_t i = 0; i < partCells; i++) {
            coeffsCalculator_.calculateBoundary(i);
            placeAllCoeffs();
        }
    }
}

void SleMatrixBuilder::placeAllCoeffs() {
    double a_w = coeffsCalculator_.getAw();
    double a_e = coeffsCalculator_.getAe();
    double a_n = coeffsCalculator_.getAn();
    double a_s = coeffsCalculator_.getAs();
    double a_p = coeffsCalculator_.getAp();

    size_t posW_ = coeffsCalculator_.get_wNum();
    size_t posE_ = coeffsCalculator_.get_eNum();
    size_t posN_ = coeffsCalculator_.get_nNum();
    size_t posS_ = coeffsCalculator_.get_sNum();
    size_t posP_ = coeffsCalculator_.get_pNum() - 1;

    bool isInteriorW_ = coeffsCalculator_.is_wInterior();
    bool isInteriorE_ = coeffsCalculator_.is_eInterior();
    bool isInteriorN_ = coeffsCalculator_.is_nInterior();
    bool isInteriorS_ = coeffsCalculator_.is_sInterior();

    placeCoeffsOtherDiags(posP_, posW_, -a_w, isInteriorW_);
    placeCoeffsOtherDiags(posP_, posE_, -a_e, isInteriorE_);
    placeCoeffsOtherDiags(posP_, posN_, -a_n, isInteriorN_);
    placeCoeffsOtherDiags(posP_, posS_, -a_s, isInteriorS_);
    placeCoeffsMainDiag(posP_, posP_, a_p);

    pSleSolver_->placeRhsValue(posP_, coeffsCalculator_.getRHS());


    aP_[posP_] = a_p;
    dataPort_.setRhs(posP_, coeffsCalculator_.getRHS());
    dataPort_.set_b(posP_, coeffsCalculator_.get_b());
    saveCoeff(posW_, a_w, aW_);
    saveCoeff(posE_, a_e, aE_);
    saveCoeff(posN_, a_n, aN_);
    saveCoeff(posS_, a_s, aS_);
}


void SleMatrixBuilder::placeCoeffsMainDiag(size_t rowNum, 
                                        size_t colNum, double value) {  
    pSleSolver_->placeCoeff(rowNum, colNum, value);                                        
}

void SleMatrixBuilder::placeCoeffsOtherDiags(size_t rowNum, 
                        size_t colNum, double value, bool isInteriorCell) {
    if (isInteriorCell) {
        pSleSolver_->placeCoeff(rowNum, colNum - 1, value);
    }
}

void SleMatrixBuilder::createMatrixAndVectors() {
    size_t matrixDimention_ = dataPort_.getAllCellsAmount();
    pSleSolver_->createContainers(matrixDimention_);
}

void SleMatrixBuilder::saveCoeff(size_t pos, double value, 
                                            std::vector<double>& coeff) {
    if (0 < pos) {
        coeff.at(pos - 1) = value;
    }
}

}