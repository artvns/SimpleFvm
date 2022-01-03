#include "UFlux.h"

namespace fvmsolver {

UFlux::UFlux(uPtrDataPort spData) : 
                    spData_(std::move(spData)),
                    data_(*spData_) {
    
}

void UFlux::calculate(size_t step) {
    double RHO_ = data_.getRHO();

    size_t nUp = data_.getNumUp(step) - 1;
    size_t nUw = data_.getNumUw(step) - 1;
    size_t nUe = data_.getNumUe(step) - 1;

    size_t nVnw = data_.getNumVnw(step) - 1;
    size_t nVne = data_.getNumVne(step) - 1;
    size_t nVsw = data_.getNumVsw(step) - 1;
    size_t nVse = data_.getNumVse(step) - 1;

    double dX = data_.get_dX(step);
    double dY = data_.get_dY(step);

    double uP = data_.get_u(nUp);
    double uW = data_.get_u(nUw);
    double uE = data_.get_u(nUe);

    double vNW = data_.get_v(nVnw);
    double vNE = data_.get_v(nVne);
    double vSW = data_.get_v(nVsw);
    double vSE = data_.get_v(nVse);

    Fw_ = 0.5 * RHO_ * (uP + uW) * dY;
    Fe_ = 0.5 * RHO_ * (uP + uE) * dY;
    Fn_ = 0.5 * RHO_ * (vNW + vNE) * dX;
    Fs_ = 0.5 * RHO_ * (vSW + vSE) * dX;
}

}