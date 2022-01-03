#ifndef SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSMANAGER_H
#define SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSMANAGER_H

#include <cstddef>
#include <memory>
#include <string>

#include "SettingsComponents/AlgorithmSettings.h"
#include "SettingsComponents/DifferencingSchemeSettings.h"
#include "SettingsComponents/ResidualsOutputSettings.h"
#include "SolverSettingsValidation/SolverSettingsValidatior.h"

#include "Config.h"


namespace fvmsolver {

class SettingsManager {
public:
    SettingsManager();

    void setNumberOfIterations(const size_t iterations);

    void generateSolverConfig();
    void validateSolverConfig();

    void chooseAlgorithmSIMPLE();
    void chooseAlgorithmSIMPLER();
    void chooseAlgorithmPISO();
    
    void chooseSchemeCentral();
    void chooseSchemeUpwind();
    void chooseSchemeHybrid();

    void chooseResidualsOutputConsole();
    void chooseResidualsOutputFile(const std::string fullFileName);

    std::shared_ptr<Config> getConfig();

private:
    std::shared_ptr<Config> spConfig_ = nullptr;

    AlgorithmSettings algorithm_;
    DifferencingSchemeSettings differencingScheme_;
    ResidualsOutputSettings residsOutputSettings_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSMANAGER_H