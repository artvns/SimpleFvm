#include "CentralDifferencingScheme.h"

namespace fvmsolver {

CentralDifferencingScheme::CentralDifferencingScheme() {

}

double CentralDifferencingScheme::a_w(double diffusion_w, double flux_w) {
    return diffusion_w + 0.5 * flux_w;
}

double CentralDifferencingScheme::a_e(double diffusion_e, double flux_e) {
    return diffusion_e - 0.5 * flux_e;
}

double CentralDifferencingScheme::a_n(double diffusion_n, double flux_n) {
    return diffusion_n - 0.5 * flux_n;
}

double CentralDifferencingScheme::a_s(double diffusion_s, double flux_s) {
    return diffusion_s + 0.5 * flux_s;
}

double CentralDifferencingScheme::deltaF(double flux_w, double flux_e, 
                                            double flux_s, double flux_n) {
    return (flux_e - flux_w) + (flux_n - flux_s);
}

}