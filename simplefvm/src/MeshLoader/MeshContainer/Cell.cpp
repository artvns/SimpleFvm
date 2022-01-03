#include "Cell.h"

namespace meshloader {

Cell::Cell(size_t globalNum, size_t interiorNum) : 
                        globalNum_(globalNum),
                        interiorNum_(interiorNum) {
    
}

Cell::Cell(size_t globalNum) : 
                        globalNum_(globalNum) {
    
}

size_t Cell::getGlobalNum() const {
    return globalNum_;
}

size_t Cell::getInteriorNum() const {
    return interiorNum_;
}

void Cell::setInteriorNum(size_t interiorNum) {
    interiorNum_ = interiorNum;
}

double Cell::getValue() const {
    return value_;
}

void Cell::setValue(double value) {
    value_ = value;
}

double Cell::get_dX() const {
    return dx_;
}

void Cell::set_dX(double dx) {
    dx_ = dx;
}

double Cell::get_dY() const {
    return dy_;
}

void Cell::set_dY(double dy) {
    dy_ = dy;
}

}