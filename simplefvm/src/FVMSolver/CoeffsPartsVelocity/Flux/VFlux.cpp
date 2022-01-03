#include "VFlux.h"

namespace fvmsolver {

VFlux::VFlux(uPtrDataPort spData) :
                    spData_(std::move(spData)),
                    data_(*spData_) {

}

void VFlux::calculate(size_t step) {
    double RHO_ = data_.getRHO();

    size_t nVp = data_.getNumVp(step) - 1;
    size_t nVn = data_.getNumVn(step) - 1;
    size_t nVs = data_.getNumVs(step) - 1;

    size_t nUwn = data_.getNumUwn(step) - 1;
    size_t nUws = data_.getNumUws(step) - 1;
    size_t nUen = data_.getNumUen(step) - 1;
    size_t nUes = data_.getNumUes(step) - 1;

    double dY = data_.get_dY(step);
    double dX = data_.get_dX(step);

    double vP = data_.get_v(nVp);
    double vN = data_.get_v(nVn);
    double vS = data_.get_v(nVs);

    double uWN = data_.get_u(nUwn);
    double uWS = data_.get_u(nUws);
    double uEN = data_.get_u(nUen);
    double uES = data_.get_u(nUes);

    Fw_ = 0.5 * RHO_ * (uWN + uWS) * dY;
    Fe_ = 0.5 * RHO_ * (uEN + uES) * dY;
    Fn_ = 0.5 * RHO_ * (vP + vN) * dX;
    Fs_ = 0.5 * RHO_ * (vP + vS) * dX;
}

}