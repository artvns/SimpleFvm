#include "SolverSettingsValidatior.h"

namespace fvmsolver {

SolverSettingsValidatior::SolverSettingsValidatior(
        const std::shared_ptr<Config>& spConfig) :
                        algorithm_(spConfig->algorithm),
                        diffScheme_(spConfig->differencingScheme) {

}

void SolverSettingsValidatior::validateSettings() const {
    validateAlgorithmState();
    validateDiffSchemeState();
}

void SolverSettingsValidatior::validateAlgorithmState() const {
    if (EnumAlgorithm::ALGORITHM_NOT_CHOSEN == algorithm_) {
        throw customexceptions::SolverSettingsException(
                    "Algorithm is not being chosen...");
    }
}

void SolverSettingsValidatior::validateDiffSchemeState() const {
    if (EnumDifferencingScheme::DIFF_SCHEME_NOT_CHOSEN == diffScheme_) {
        throw customexceptions::SolverSettingsException(
                    "Difference scheme is not being chosen...");
    }
}

}