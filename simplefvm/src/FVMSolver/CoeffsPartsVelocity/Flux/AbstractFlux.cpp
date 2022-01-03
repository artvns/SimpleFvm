#include "AbstractFlux.h"

namespace fvmsolver {

AbstractFlux::AbstractFlux() {

}

AbstractFlux::~AbstractFlux() {

}

double AbstractFlux::getFw() {
    return Fw_;
}

double AbstractFlux::getFe() {
    return Fe_;
}

double AbstractFlux::getFn() {
    return Fn_;
}

double AbstractFlux::getFs() {
    return Fs_;
}

}