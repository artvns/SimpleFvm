#include "ResidualsOutputSettings.h"

namespace fvmsolver {

ResidualsOutputSettings::ResidualsOutputSettings() {

}

void ResidualsOutputSettings::chooseConsoleOutput() {
    isConsoleOutput_ = true;
}

void ResidualsOutputSettings::chooseFileOutput(
                                const std::string residualsFullFileName) {
    isFileOutput_ = true;
    residualsFullFileName_ = residualsFullFileName;
}

bool ResidualsOutputSettings::isConsoleOutput() {
    return isConsoleOutput_;
}

bool ResidualsOutputSettings::isFileOutput() {
    return isFileOutput_;
}

std::string ResidualsOutputSettings::getResidualsFullFileName() {
    return residualsFullFileName_;
}

}