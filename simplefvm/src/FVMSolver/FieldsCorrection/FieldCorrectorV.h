#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORV_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORV_H

#include "AbstractFieldCorrector.h"
#include "FieldCorrectorVPort.h"


namespace fvmsolver {

class FieldCorrectorV : public AbstractFieldCorrector {
private:
    using uPtrDataPort = std::unique_ptr<FieldCorrectorVPort>;

public:
    FieldCorrectorV(uPtrDataPort spData);

    void correct(size_t step) override;

private:
    uPtrDataPort spData_ = nullptr;
    FieldCorrectorVPort& data_;
    CalculatedScalar& vStar_;
    CalculatedScalar& pPrime_;

    const double relaxFactor_ = 0.7;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORV_H