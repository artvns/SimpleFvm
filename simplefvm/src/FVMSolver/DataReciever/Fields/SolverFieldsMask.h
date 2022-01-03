#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_FIELDS_SOLVERFIELDSMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_FIELDS_SOLVERFIELDSMASK_H

#include <cstddef>
#include <string>

#include "DataStores/FieldsStores/FieldsStore.h"


namespace fvmsolver {

class SolverFieldsMask {
private:
    using RecievedDataStore = datastores::FieldsStore;

public:
    SolverFieldsMask(RecievedDataStore& store);

    double getU(size_t index) const;
    double getV(size_t index) const;
    double getP(size_t index) const;

    void setU(size_t index, double value);
    void setV(size_t index, double value);
    void setP(size_t index, double value);

    void set_uCellCentered(size_t index, double value);
    void set_vCellCentered(size_t index, double value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_FIELDS_SOLVERFIELDSMASK_H