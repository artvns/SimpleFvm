#include "FieldInterpolatorU.h"

namespace fvmsolver {

FieldInterpolatorU::FieldInterpolatorU(
                        uPtrDataPort spData) :
                                spData_(std::move(spData)),
                                data_(*spData_) {

}

void FieldInterpolatorU::interpolate(size_t step) {
    size_t num = data_.getNumPp(step) - 1;

    size_t nUw = data_.getNumUw(step) - 1;
    size_t nUe = data_.getNumUe(step) - 1;

    double uCellCentered = data_.getU(nUw) 
            + ((data_.getU(nUe) - data_.getU(nUw)) / data_.get_dX(num)) 
                    * 0.5 * data_.get_dX(num);

    data_.setCellCenteredU(num, uCellCentered);
}

}