#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTCONSOLE_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTCONSOLE_H

#include <cstddef>
#include <iostream>

#include "AbstractResidualsOutput.h"


namespace fvmsolver {

class ResidualsOutputConsole : public AbstractResidualsOutput {
public:
    ResidualsOutputConsole();

    void saveStepResiduals(size_t stepNumber) override;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTCONSOLE_H

