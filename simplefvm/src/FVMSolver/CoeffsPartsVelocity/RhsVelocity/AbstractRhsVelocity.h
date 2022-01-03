#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_ABSTRACTRHSVELOCITY_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_ABSTRACTRHSVELOCITY_H

#include <cstddef>
#include <memory>

#include "RhsUPort.h"
#include "RhsVPort.h"


namespace fvmsolver {

class AbstractRhsVelocity {
public:
    AbstractRhsVelocity();
    virtual ~AbstractRhsVelocity() = 0;

    virtual void calculate(size_t step, double Sc, double a_p) = 0;

    double getRhsValue();
    double get_bValue();

protected:
    double rhsValue_ = 0.0;
    double bValue_ = 0.0;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_ABSTRACTRHSVELOCITY_H