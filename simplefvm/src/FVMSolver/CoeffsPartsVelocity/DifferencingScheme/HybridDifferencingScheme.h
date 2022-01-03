#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_HYBRIDDIFFERENCINGSCHEME_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_HYBRIDDIFFERENCINGSCHEME_H

#include "algorithm"

#include "IDifferencingScheme.h"


namespace fvmsolver {

class HybridDifferencingScheme : public IDifferencingScheme {
public:
    HybridDifferencingScheme();

    double a_w(double diffusion_w, double flux_w) override;
    double a_e(double diffusion_e, double flux_e) override;
    double a_n(double diffusion_n, double flux_n) override;
    double a_s(double diffusion_s, double flux_s) override;
    double deltaF(double flux_w, double flux_e, double flux_s, double flux_n) override;
    
private:
    double maxValue(double a, double b, double c);

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_HYBRIDDIFFERENCINGSCHEME_H