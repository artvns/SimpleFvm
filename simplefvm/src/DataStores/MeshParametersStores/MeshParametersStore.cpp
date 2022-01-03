#include "MeshParametersStore.h"

namespace datastores {

MeshParametersStore::MeshParametersStore() {

}

void MeshParametersStore::createArrays(size_t cells) {
    dX_.create(cells);
    dY_.create(cells);
}

ArrayAdt<double>& MeshParametersStore::get_dX() {
    return dX_;
}

ArrayAdt<double>& MeshParametersStore::get_dY() {
    return dY_;
}

}