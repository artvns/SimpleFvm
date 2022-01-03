#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERP_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERP_H

#include "AbstractDataExchanger.h"


namespace fvmsolver {

class DataExchangerP : public AbstractDataExchanger {
private:
    using uPtrDataPort = std::unique_ptr<PDataExchangerPort>;

public:
    DataExchangerP(uPtrDataPort spData);

    void assignCurrentCellValues(size_t step) override;

protected:

private:
    uPtrDataPort spData_ = nullptr;
    const PDataExchangerPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERP_H