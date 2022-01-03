#ifndef SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORV_H
#define SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORV_H

#include <memory>

#include "IFieldInterpolator.h"
#include "FieldInterpolatorVPort.h"


namespace fvmsolver {

class FieldInterpolatorV : public IFieldInterpolator {
private:
    using uPtrDataPort = std::unique_ptr<FieldInterpolatorVPort>;

public:
    FieldInterpolatorV(uPtrDataPort spData);

    void interpolate(size_t step) override;

private:
    uPtrDataPort spData_ = nullptr;
    FieldInterpolatorVPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORV_H