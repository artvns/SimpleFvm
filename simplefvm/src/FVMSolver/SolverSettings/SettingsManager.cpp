#include "SettingsManager.h"

namespace fvmsolver {

SettingsManager::SettingsManager() {
    spConfig_ = std::shared_ptr<Config>(new Config());
}

void SettingsManager::generateSolverConfig() {
    spConfig_->algorithm = algorithm_.getType();
    spConfig_->differencingScheme = differencingScheme_.getType();
    spConfig_->isResidsOutputConsole = residsOutputSettings_.isConsoleOutput();
    spConfig_->isResidsOutputFile = residsOutputSettings_.isFileOutput();
    spConfig_->basicSolverVariables.setResidualsFullFileName(
                    residsOutputSettings_.getResidualsFullFileName()); 
}

void SettingsManager::validateSolverConfig() {
    SolverSettingsValidatior solverSettingsValidatior_(spConfig_);
    solverSettingsValidatior_.validateSettings();
}

void SettingsManager::setNumberOfIterations(const size_t iterations) {
    spConfig_->basicSolverVariables.setNumberOfIterations(iterations);
}

void SettingsManager::chooseAlgorithmSIMPLE() {
    algorithm_.chooseSIMPLE();
}

void SettingsManager::chooseAlgorithmSIMPLER() {
    algorithm_.chooseSIMPLER();
}

void SettingsManager::chooseAlgorithmPISO() {
    algorithm_.choosePISO();
}

void SettingsManager::chooseSchemeCentral() {
    differencingScheme_.chooseCentral();
}

void SettingsManager::chooseSchemeUpwind() {
    differencingScheme_.chooseUpwind();
}

void SettingsManager::chooseSchemeHybrid() {
    differencingScheme_.chooseHybrid();
}

void SettingsManager::chooseResidualsOutputConsole() {
    residsOutputSettings_.chooseConsoleOutput();
}

void SettingsManager::chooseResidualsOutputFile(
                            const std::string fullFileName) {

    residsOutputSettings_.chooseFileOutput(fullFileName);
}

std::shared_ptr<Config> SettingsManager::getConfig() {
    return spConfig_;
}

}