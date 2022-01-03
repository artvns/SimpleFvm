#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDSOUTPUTERCREATOR_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDSOUTPUTERCREATOR_H

#include <memory>
#include <string>

#include "FVMSolver/SolverSettings/Config.h"

#include "ResidualsOutputer.h"


namespace fvmsolver {

class ResidsOutputerCreator {
public:
    ResidsOutputerCreator(const Config& config);

    void configureResidsOutputer();
    std::shared_ptr<ResidualsOutputer> createResidsOutputer();

private:
    const std::string fullFileName_ = "";
    const bool isConsoleOutput_ = false;
    const bool isFileOutput_ = false;
    std::vector<std::unique_ptr<AbstractResidualsOutput>> outputList_;

    std::shared_ptr<ResidualsOutputer> spResidsOutputer_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDSOUTPUTERCREATOR_H