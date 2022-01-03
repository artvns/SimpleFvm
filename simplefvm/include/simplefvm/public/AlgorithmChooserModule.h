#ifndef SIMPLEFVM_ALGORITHMCHOOSERMODULE_H
#define SIMPLEFVM_ALGORITHMCHOOSERMODULE_H

#include <memory>

#include "MSolverMacros.h"


namespace mainsolver {

class SolverAlgorithmChooser;

class SFVM_API_ AlgorithmChooserModule {
public:
    AlgorithmChooserModule();
    ~AlgorithmChooserModule();

    void select_SIMPLE();
    void select_SIMPLER();
    void select_PISO();

    bool isSIMPLE();
    bool isSIMPLER();
    bool isPISO();

    SolverAlgorithmChooser& getAlgorithmChooser() const;

private:
    SolverAlgorithmChooser* spObj_ = nullptr;
};

}
#endif // SIMPLEFVM_ALGORITHMCHOOSERMODULE_H