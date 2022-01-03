#include "AbstractDiffusion.h"

namespace fvmsolver {

AbstractDiffusion::AbstractDiffusion(uPtrDataPort spData) :
                                        spData_(std::move(spData)),
                                        data_(*spData_) {
    
}

AbstractDiffusion::~AbstractDiffusion() {

}

double AbstractDiffusion::getDw() {
    return Dw_;
}

double AbstractDiffusion::getDe() {
    return De_;
}

double AbstractDiffusion::getDn() {
    return Dn_;
}

double AbstractDiffusion::getDs() {
    return Ds_;
}

}