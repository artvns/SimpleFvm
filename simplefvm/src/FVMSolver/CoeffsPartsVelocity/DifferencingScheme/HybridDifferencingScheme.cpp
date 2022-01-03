#include "HybridDifferencingScheme.h"

namespace fvmsolver {

HybridDifferencingScheme::HybridDifferencingScheme() {

}

double HybridDifferencingScheme::a_w(double diffusion_w, double flux_w) {
    return maxValue(flux_w, (diffusion_w + 0.5 * flux_w), 0.0);
}

double HybridDifferencingScheme::a_e(double diffusion_e, double flux_e) {
    return maxValue(-flux_e, (diffusion_e - 0.5 * flux_e), 0.0);
}

double HybridDifferencingScheme::a_n(double diffusion_n, double flux_n) {
    return maxValue(-flux_n, (diffusion_n - 0.5 * flux_n), 0.0);
}

double HybridDifferencingScheme::a_s(double diffusion_s, double flux_s) {
    return maxValue(flux_s, (diffusion_s + 0.5 * flux_s), 0.0);
}

double HybridDifferencingScheme::deltaF(double flux_w, double flux_e, 
                                            double flux_s, double flux_n) {
    return (flux_e - flux_w) + (flux_n - flux_s);
}

double HybridDifferencingScheme::maxValue(double a, double b, double c) {
    double temp = std::max(a, b);
    return std::max(temp, c);
}

}