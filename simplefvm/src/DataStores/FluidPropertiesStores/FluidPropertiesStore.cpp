#include "FluidPropertiesStore.h"

namespace datastores {

FluidPropertiesStore::FluidPropertiesStore() {

}

double FluidPropertiesStore::getRHO() const {
    return RHO_;
}

double FluidPropertiesStore::getMU() const {
    return MU_;
}

void FluidPropertiesStore::setRHO(double RHO) {
    RHO_ = RHO;
}

void FluidPropertiesStore::setMU(double MU) {
    MU_ = MU;
}

}