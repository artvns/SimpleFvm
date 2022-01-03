#ifndef SIMPLEFVM_DATASTORES_MESHPARAMETERSSTORES_MESHPARAMETERSSTORE_H
#define SIMPLEFVM_DATASTORES_MESHPARAMETERSSTORES_MESHPARAMETERSSTORE_H

#include <cstddef>

#include "../Adt/ArrayAdt.cpp"


namespace datastores {

class MeshParametersStore {
public:
    MeshParametersStore();

    void createArrays(size_t cells);

    ArrayAdt<double>& get_dX();
    ArrayAdt<double>& get_dY();

private:
    ArrayAdt<double> dX_;
    ArrayAdt<double> dY_;
};

}
#endif // SIMPLEFVM_DATASTORES_MESHPARAMETERSSTORES_MESHPARAMETERSSTORE_H