#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERV_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERV_H

#include "AbstractDataExchanger.h"


namespace fvmsolver {

class DataExchangerV : public AbstractDataExchanger {
private:
    using uPtrDataPort = std::unique_ptr<VDataExchangerPort>;

public:
    DataExchangerV(uPtrDataPort spData);

    void assignCurrentCellValues(size_t step) override;
    void add_de(size_t step, double a_p) override;
    
protected:

private:
    uPtrDataPort spData_ = nullptr;
    VDataExchangerPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERV_H