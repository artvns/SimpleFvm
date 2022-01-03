#include "AlgorithmSettings.h"

namespace fvmsolver {

AlgorithmSettings::AlgorithmSettings() {

}

void AlgorithmSettings::chooseSIMPLE() {
    type_ = ALGORITHM_SIMPLE;
}

void AlgorithmSettings::chooseSIMPLER() {
    type_ = ALGORITHM_SIMPLER;
}

void AlgorithmSettings::choosePISO() {
    type_ = ALGORITHM_PISO;
}

EnumAlgorithm AlgorithmSettings::getType() {
    return type_;
}

}