#include "FieldInterpolatorV.h"

namespace fvmsolver {

FieldInterpolatorV::FieldInterpolatorV(
                uPtrDataPort spData) :
                        spData_(std::move(spData)),
                        data_(*spData_) {

}

void FieldInterpolatorV::interpolate(size_t step) {
    size_t num = data_.getNumPp(step) - 1;

    size_t nVn = data_.getNumVn(step) - 1;
    size_t nVs = data_.getNumVs(step) - 1;

    double vCellCentered = data_.getV(nVs)
                + ((data_.getV(nVn) - data_.getV(nVs)) / data_.get_dY(num)) 
                        * 0.5 * data_.get_dY(num);

    data_.setCellCenteredV(num, vCellCentered);
}

}