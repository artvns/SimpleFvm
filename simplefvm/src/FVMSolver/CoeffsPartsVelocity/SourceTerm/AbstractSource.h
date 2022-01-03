#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_ABSTRACTSOURCE_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_ABSTRACTSOURCE_H

#include <cstddef>
#include <memory>

#include "AbstractSourcePort.h"


namespace fvmsolver {

class AbstractSource {
protected:
    using uPtrDataPort = std::unique_ptr<AbstractSourcePort>;

public:
    AbstractSource();
    virtual ~AbstractSource() = 0;

    virtual void calculate(size_t step) = 0;
    
    double getSp();
    double getSc();

protected:
    double Sp_ = 0.0;
    double Sc_ = 0.0;
    
private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_ABSTRACTSOURCE_H