#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_IDIFFERENCINGSCHEME_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_IDIFFERENCINGSCHEME_H


namespace fvmsolver {

class IDifferencingScheme {
public:
    virtual double a_w(double diffusion_w, double flux_w) = 0;
    virtual double a_e(double diffusion_e, double flux_e) = 0;
    virtual double a_n(double diffusion_n, double flux_n) = 0;
    virtual double a_s(double diffusion_s, double flux_s) = 0;
    virtual double deltaF(double flux_w, double flux_e, 
                                double flux_s, double flux_n) = 0;

    virtual ~IDifferencingScheme() {};
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFERENCINGSCHEME_IDIFFERENCINGSCHEME_H