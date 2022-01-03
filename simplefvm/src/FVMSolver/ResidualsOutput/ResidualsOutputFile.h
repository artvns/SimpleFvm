#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTFILE_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTFILE_H

#include <cstddef>
#include <fstream>
#include <string>

#include "AbstractResidualsOutput.h"


namespace fvmsolver {

class ResidualsOutputFile : public AbstractResidualsOutput {
public:
    ResidualsOutputFile(const std::string fullFileName);
    ~ResidualsOutputFile();

    void saveStepResiduals(size_t stepNumber) override;

private:
    std::ofstream fout_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTFILE_H

