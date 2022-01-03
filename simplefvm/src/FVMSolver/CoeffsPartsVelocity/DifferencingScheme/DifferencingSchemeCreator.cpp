#include "DifferencingSchemeCreator.h"

namespace fvmsolver {

DifferencingSchemeCreator::DifferencingSchemeCreator(
                    Config& config) : 
                            config_(config),
                            schemeType_(config_.differencingScheme) {

}

std::shared_ptr<IDifferencingScheme> DifferencingSchemeCreator::create() {
    if (DIFF_SCHEME_CENTRAL == schemeType_) {
        return std::shared_ptr<CentralDifferencingScheme>(
            new CentralDifferencingScheme());
    }
    if (DIFF_SCHEME_UPWIND == schemeType_) {
        return std::shared_ptr<UpwindDifferencingScheme>(
            new UpwindDifferencingScheme());
    }
    if (DIFF_SCHEME_HYBRID == schemeType_) {
        return std::shared_ptr<HybridDifferencingScheme>(
            new HybridDifferencingScheme());
    }
    std::cout << "<------- Scheme is not selected. The default scheme is Upwind ------->" << '\n';
    return std::shared_ptr<UpwindDifferencingScheme>(
            new UpwindDifferencingScheme());
}

}