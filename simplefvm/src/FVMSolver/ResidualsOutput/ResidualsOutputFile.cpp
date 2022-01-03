#include "ResidualsOutputFile.h"

namespace fvmsolver {

ResidualsOutputFile::ResidualsOutputFile(
        const std::string fullFileName) :
                            fout_(fullFileName) {

    fout_.exceptions(std::ofstream::badbit | std::ofstream::failbit);
}

ResidualsOutputFile::~ResidualsOutputFile() {
    if (fout_.is_open()) {
        fout_.close();
    }
}

void ResidualsOutputFile::saveStepResiduals(size_t stepNumber) {
    if (0 == stepNumber) {
        fout_ << "Iteration" << "\t\t";
        fout_ << "p" << "\t\t";
        fout_ << "u" << "\t\t";
        fout_ << "v" << std::endl;
    }

    fout_ << stepNumber + 1 << "\t\t";
    fout_ << residualP_ << "\t\t";
    fout_ << residualU_ << "\t\t";
    fout_ << residualV_ << std::endl;
}

}