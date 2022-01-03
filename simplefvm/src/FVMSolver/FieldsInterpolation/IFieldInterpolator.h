#ifndef SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_IFIELDINTERPOLATOR_H
#define SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_IFIELDINTERPOLATOR_H

#include <cstddef>


namespace fvmsolver {

class IFieldInterpolator {
public:
    virtual void interpolate(size_t step) = 0;

    virtual ~IFieldInterpolator() {};

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_IFIELDINTERPOLATOR_H 