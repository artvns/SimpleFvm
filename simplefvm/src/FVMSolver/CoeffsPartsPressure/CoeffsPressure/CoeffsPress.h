#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESS_H

#include <cstddef>
#include <memory>

#include "CoeffsPressPort.h"


namespace fvmsolver {

class CoeffsPress {
private:
    using uPtrDataPort = std::unique_ptr<CoeffsPressPort>;

public:
    CoeffsPress(uPtrDataPort spData);

    void calculate(size_t step);

    double getAw();
    double getAe();
    double getAn();
    double getAs();

private:
    uPtrDataPort spData_ = nullptr;
    const CoeffsPressPort& data_;

    double a_w_ = 0.0;
    double a_e_ = 0.0;
    double a_n_ = 0.0;
    double a_s_ = 0.0;

    bool isNotZeroNumber(const size_t num);
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESS_H

    