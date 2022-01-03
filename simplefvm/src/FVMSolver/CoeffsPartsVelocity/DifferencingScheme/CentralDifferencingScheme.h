#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_CENTRALDIFFERENCINGSCHEME_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_CENTRALDIFFERENCINGSCHEME_H

#include "IDifferencingScheme.h"


namespace fvmsolver {

class CentralDifferencingScheme : public IDifferencingScheme {
public:
    CentralDifferencingScheme();

    double a_w(double diffusion_w, double flux_w) override;
    double a_e(double diffusion_e, double flux_e) override;
    double a_n(double diffusion_n, double flux_n) override;
    double a_s(double diffusion_s, double flux_s) override;
    double deltaF(double flux_w, double flux_e, 
                    double flux_s, double flux_n) override;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_CENTRALDIFFERENCINGSCHEME_H