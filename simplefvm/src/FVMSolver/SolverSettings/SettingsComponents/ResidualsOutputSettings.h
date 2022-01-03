#ifndef SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_RESIDUALSOUTPUTSETTINGS_H
#define SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_RESIDUALSOUTPUTSETTINGS_H

#include <string>


namespace fvmsolver {

class ResidualsOutputSettings {
public:
    ResidualsOutputSettings();

    void chooseConsoleOutput();
    void chooseFileOutput(const std::string residualsFullFileName);

    bool isConsoleOutput();
    bool isFileOutput();
    std::string getResidualsFullFileName();

private:
    bool isConsoleOutput_ = false;
    bool isFileOutput_ = false;
    std::string residualsFullFileName_ = "";
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SETTINGSCOMPONENTS_RESIDUALSOUTPUTSETTINGS_H