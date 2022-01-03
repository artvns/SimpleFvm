#include "AbstractSource.h"

namespace fvmsolver {

AbstractSource::AbstractSource() {

}

AbstractSource::~AbstractSource() {
    
}

double AbstractSource::getSp() {
    return Sp_;
}

double AbstractSource::getSc() {
    return Sc_;
}

}