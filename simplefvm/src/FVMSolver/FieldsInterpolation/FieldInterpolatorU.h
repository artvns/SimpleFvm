#ifndef SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORU_H
#define SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORU_H

#include <memory>

#include "IFieldInterpolator.h"
#include "FieldInterpolatorUPort.h"


namespace fvmsolver {

class FieldInterpolatorU : public IFieldInterpolator {
private:
    using uPtrDataPort = std::unique_ptr<FieldInterpolatorUPort>;

public:
    FieldInterpolatorU(uPtrDataPort spData);

    void interpolate(size_t step) override;

private:
    uPtrDataPort spData_ = nullptr;
    FieldInterpolatorUPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORU_H