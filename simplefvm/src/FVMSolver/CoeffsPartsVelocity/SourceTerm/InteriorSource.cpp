#include "InteriorSource.h"

namespace fvmsolver {

InteriorSource::InteriorSource(){

}

void InteriorSource::calculate(size_t step) {
    
}

void InteriorSource::calculateForUMesh() {
    Sp_ = 0.0;
    Sc_ = 0.0;
}

void InteriorSource::calculateForVMesh() {
    Sp_ = 0.0;
    Sc_ = 0.0;
}

}