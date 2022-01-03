#ifndef SIMPLEFVM_MATHTOOLS_SLESOLVERS_ISLESOLVERVECTOR_H
#define SIMPLEFVM_MATHTOOLS_SLESOLVERS_ISLESOLVERVECTOR_H

#include <cstddef>


namespace mathtools {

class ISleSolverVector {
public:
    virtual void createVector(size_t size) = 0;
    virtual double getValue(size_t i) = 0;
    virtual void setValue(size_t i, double value) = 0;
    virtual size_t getSize() = 0;

    virtual ~ISleSolverVector() {};
};

}
#endif // SIMPLEFVM_MATHTOOLS_SLESOLVERS_ISLESOLVERVECTOR_H