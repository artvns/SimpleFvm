#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_STATICWALLSOURCE_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_STATICWALLSOURCE_H

#include "AbstractSource.h"
#include "AbstractSourcePort.h"


namespace fvmsolver {

class StaticWallSource : public AbstractSource {
public:
    StaticWallSource(uPtrDataPort spData);

    void calculate(size_t step) override;
    
protected:
    uPtrDataPort spData_ = nullptr;
    const AbstractSourcePort& data_;

private:
    double MU_ = 0.0;
    double velocity_ = 0.0;
    double dX_ = 0.0;
    double dY_ = 0.0;

    EnumAdjacentCellTypes wType_;
    EnumAdjacentCellTypes eType_;
    EnumAdjacentCellTypes nType_;
    EnumAdjacentCellTypes sType_;

    void calculateForUMesh();
    void calculateForVMesh();
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_STATICWALLSOURCE_H