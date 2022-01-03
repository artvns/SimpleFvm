#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSV_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSV_H

#include "AbstractRhsVelocity.h"


namespace fvmsolver {

class RhsV : public AbstractRhsVelocity{
private:
    using uPtrDataPort = std::unique_ptr<RhsVPort>;

public:
    RhsV(uPtrDataPort spData);

    void calculate(size_t step, double Sc, double a_p) override;

protected:

private:
    uPtrDataPort spData_ = nullptr;
    const RhsVPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSV_H