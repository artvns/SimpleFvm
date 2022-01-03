#ifndef SIMPLEFVM_DATASTORES_FLUIDPROPERTIESSTORES_FLUIDPROPERTIESSTORE_H
#define SIMPLEFVM_DATASTORES_FLUIDPROPERTIESSTORES_FLUIDPROPERTIESSTORE_H

namespace datastores {

class FluidPropertiesStore {
public:
    FluidPropertiesStore();

    double getRHO() const;
    double getMU() const;

    void setRHO(double RHO);
    void setMU(double MU);

private:
    double RHO_ = 0.0;
    double MU_ = 0.0;
};

}
#endif // SIMPLEFVM_DATASTORES_FLUIDPROPERTIESSTORES_FLUIDPROPERTIESSTORE_H