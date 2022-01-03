#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_ABSTRACTDATAEXCHANGER_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_ABSTRACTDATAEXCHANGER_H

#include <cstddef>
#include <memory>

#include "UDataExchangerPort.h"
#include "VDataExchangerPort.h"
#include "PDataExchangerPort.h"


namespace fvmsolver {

class AbstractDataExchanger {
public:
    AbstractDataExchanger();
    virtual~AbstractDataExchanger() = 0;

    virtual void assignCurrentCellValues(size_t step) = 0;

    double get_dw();
    double get_de();
    double get_dn();
    double get_ds();

    virtual void add_de(size_t step, double value) {};
    
protected:
    double dw_var_ = 0.0;
    double de_var_ = 0.0;
    double dn_var_ = 0.0;
    double ds_var_ = 0.0;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_ABSTRACTDATAEXCHANGER_H