#include "UpwindDifferencingScheme.h"

namespace fvmsolver {

UpwindDifferencingScheme::UpwindDifferencingScheme() {

}

double UpwindDifferencingScheme::a_w(double diffusion_w, double flux_w) {
    return diffusion_w + maxValue(flux_w, 0.0);
}

double UpwindDifferencingScheme::a_e(double diffusion_e, double flux_e) {
    return diffusion_e + maxValue(-flux_e, 0.0);
}

double UpwindDifferencingScheme::a_n(double diffusion_n, double flux_n) {
    return diffusion_n + maxValue(-flux_n, 0.0);
}

double UpwindDifferencingScheme::a_s(double diffusion_s, double flux_s) {
    return diffusion_s + maxValue(flux_s, 0.0);
}

double UpwindDifferencingScheme::deltaF(double flux_w, double flux_e, 
                                            double flux_s, double flux_n) {
    return (flux_e - flux_w) + (flux_n - flux_s);
}

double UpwindDifferencingScheme::maxValue(double a, double b) {
    return std::max(a, b);
}

}