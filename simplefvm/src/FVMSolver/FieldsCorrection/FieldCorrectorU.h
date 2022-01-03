#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_VELOCITYCORRECTORU_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_VELOCITYCORRECTORU_H

#include "AbstractFieldCorrector.h"
#include "FieldCorrectorUPort.h"


namespace fvmsolver {

class FieldCorrectorU : public AbstractFieldCorrector {
private:
    using uPtrDataPort = std::unique_ptr<FieldCorrectorUPort>;

public:
    FieldCorrectorU(uPtrDataPort spData);

    void correct(size_t step) override;

private:
    uPtrDataPort spData_ = nullptr;
    FieldCorrectorUPort& data_;
    CalculatedScalar& uStar_;
    CalculatedScalar& pPrime_;

    const double relaxFactor_ = 0.7;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_VELOCITYCORRECTORU_H    