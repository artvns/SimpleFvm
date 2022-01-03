#include "UDiffusion.h"

namespace fvmsolver {

UDiffusion::UDiffusion(uPtrDataPort spData) : 
                            AbstractDiffusion(std::move(spData)) {

}


void UDiffusion::calculate(size_t step) {
    size_t num = 0;
    num = data_.getNumCellp(step) - 1;

    MU_ = data_.getMU();

    Dw_ = MU_ * data_.get_dY(num) / data_.get_dX(num);
    De_ = MU_ * data_.get_dY(num) / data_.get_dX(num);
    Dn_ = MU_ * data_.get_dX(num) / data_.get_dY(num);
    Ds_ = MU_ * data_.get_dX(num) / data_.get_dY(num);
}

}