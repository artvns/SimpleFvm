#ifndef SIMPLEFVM_SLESOLVERCHOOSERMODULE_H
#define SIMPLEFVM_SLESOLVERCHOOSERMODULE_H

#include <memory>

#include "MSolverMacros.h"


namespace mainsolver {

class SolverSleSolverChooser;

class SFVM_API_ SleSolverChooserModule {
public:
    SleSolverChooserModule();
    ~SleSolverChooserModule();

    void select_EIGEN_SOLVER();

    SolverSleSolverChooser& getSleSolverChooser() const;

private:
    SolverSleSolverChooser* spObj_ = nullptr;
};

}
#endif // SIMPLEFVM_SLESOLVERCHOOSERMODULE_H