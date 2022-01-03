#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSU_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSU_H

#include "AbstractRhsVelocity.h"


namespace fvmsolver {

class RhsU : public AbstractRhsVelocity{
private:
    using uPtrDataPort = std::unique_ptr<RhsUPort>;

public:
    RhsU(uPtrDataPort spData);

    void calculate(size_t step, double Sc, double a_p) override;

protected:

private:
    uPtrDataPort spData_ = nullptr;
    const RhsUPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSU_H