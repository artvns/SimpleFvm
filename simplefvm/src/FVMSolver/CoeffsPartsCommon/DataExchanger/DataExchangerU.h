#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERU_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERU_H

#include "AbstractDataExchanger.h"


namespace fvmsolver {

class DataExchangerU : public AbstractDataExchanger {
private:
    using uPtrDataPort = std::unique_ptr<UDataExchangerPort>;

public:
    DataExchangerU(uPtrDataPort spData);

    void assignCurrentCellValues(size_t step) override;
    void add_de(size_t step, double value) override;

protected:

private:
    uPtrDataPort spData_ = nullptr;
    UDataExchangerPort& data_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERU_H