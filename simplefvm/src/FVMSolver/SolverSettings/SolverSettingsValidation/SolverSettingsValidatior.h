#ifndef SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SOLVERSETTINGSVALIDATION_SOLVERSETTINGSVALIDATIOR_H
#define SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SOLVERSETTINGSVALIDATION_SOLVERSETTINGSVALIDATIOR_H

#include <memory>

#include "CustomExceptions/SolverSettingsException.h"
#include "FVMSolver/Tools/Enums/EnumDifferencingScheme.cpp"
#include "FVMSolver/Tools/Enums/EnumAlgorithm.cpp"

#include "../Config.h"


namespace fvmsolver {

class SolverSettingsValidatior {
public:
    SolverSettingsValidatior(const std::shared_ptr<Config>& spConfig);

    void validateSettings() const;

private:
    EnumAlgorithm algorithm_ = EnumAlgorithm::ALGORITHM_NOT_CHOSEN;
    EnumDifferencingScheme diffScheme_ = 
        EnumDifferencingScheme::DIFF_SCHEME_NOT_CHOSEN;

    void validateAlgorithmState() const;
    void validateDiffSchemeState() const;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_SOLVERSETTINGSVALIDATION_SOLVERSETTINGSVALIDATIOR_H