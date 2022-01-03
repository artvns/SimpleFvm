#include "MovingWallSource.h"

namespace fvmsolver {

MovingWallSource::MovingWallSource(uPtrDataPort spData) :
                                        spData_(std::move(spData)),
                                        data_(*spData_) {

}

void MovingWallSource::calculate(size_t step) {
    size_t numP_ = data_.getNumCellp(step) - 1;
    size_t numW_ = data_.getNumCellw(step) - 1;
    size_t numE_ = data_.getNumCelle(step) - 1;
    size_t numN_ = data_.getNumCelln(step) - 1;
    size_t numS_ = data_.getNumCells(step) - 1;

    wType_ = data_.getCellType(numW_);
    eType_ = data_.getCellType(numE_);
    nType_ = data_.getCellType(numN_);
    sType_ = data_.getCellType(numS_);

    dX_ = data_.get_dX(numP_);
    dY_ = data_.get_dY(numP_);
    
    MU_ = data_.getMU();
    velocity_ = data_.getWallVelocity();

    Sp_ = 0.0;
    Sc_ = 0.0;


    if (ADJACENT_CELL_BC_GHOST == wType_) {
        calculateForVMesh();
    } 
    if (ADJACENT_CELL_BC_GHOST == eType_) {
        calculateForVMesh();
    } 
    if (ADJACENT_CELL_BC_GHOST == nType_) {
        calculateForUMesh();
    } 
    if (ADJACENT_CELL_BC_GHOST == sType_) {
        calculateForUMesh();
    }
}

void MovingWallSource::calculateForUMesh() {
    Sp_ = 2.0 * MU_ * dY_ / (dX_);
    Sc_ = 2.0 * MU_ * velocity_ * dY_ / (dX_);
}

void MovingWallSource::calculateForVMesh() {
    Sp_ = 2.0 * MU_ * dX_ / (dY_);
    Sc_ = 2.0 * MU_ * velocity_ * dX_ / (dY_);
}

}