#ifndef SIMPLEFVM_RESIDUALSSETTINGSMODULE_H
#define SIMPLEFVM_RESIDUALSSETTINGSMODULE_H

#include <memory>
#include <string>

#include "MSolverMacros.h"


namespace mainsolver {

class SolverResidualsSettingsDefiner;

class SFVM_API_ ResidualsSettingsModule {
public:
    ResidualsSettingsModule();
    ~ResidualsSettingsModule();

    void selectConsoleOutput();
    void selectFileOutput(const std::string fullFileName);

    bool isConsoleOutput();
    bool isFileOutput();

    SolverResidualsSettingsDefiner& getResidsSettingsDefiner() const;

private:
    SolverResidualsSettingsDefiner* spObj_ = nullptr;
};

}
#endif // SIMPLEFVM_RESIDUALSSETTINGSMODULE_H