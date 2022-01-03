#include "AbstractRhsVelocity.h"

namespace fvmsolver {

AbstractRhsVelocity::AbstractRhsVelocity() {

}

AbstractRhsVelocity::~AbstractRhsVelocity() {
    
}

double AbstractRhsVelocity::getRhsValue() {
    return rhsValue_;
}

double AbstractRhsVelocity::get_bValue() {
    return  bValue_;
}

}