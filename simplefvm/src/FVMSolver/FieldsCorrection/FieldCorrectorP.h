#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORP_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORP_H

#include "AbstractFieldCorrector.h"
#include "FieldCorrectorPPort.h"


namespace fvmsolver {

class FieldCorrectorP : public AbstractFieldCorrector {
private:
    using uPtrDataPort = std::unique_ptr<FieldCorrectorPPort>;

public:
    FieldCorrectorP(uPtrDataPort spData);

    void correct(size_t step) override;

private:
    uPtrDataPort spData_ = nullptr;
    FieldCorrectorPPort& data_;
    CalculatedScalar& pPrime_;

    const double relaxFactor_ = 0.3;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORP_H  