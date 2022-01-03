#ifndef SIMPLEFVM_SCHEMECHOOSERMODULE_H
#define SIMPLEFVM_SCHEMECHOOSERMODULE_H

#include <memory>

#include "MSolverMacros.h"


namespace mainsolver {

class SolverSchemeChooser;

class SFVM_API_ SchemeChooserModule {
public:
    SchemeChooserModule();
    ~SchemeChooserModule();

    void select_CENTRAL();
    void select_UPWIND();
    void select_HYBRID();

    bool isCENTRAL();
    bool isUPWIND();
    bool isHYBRID();

    SolverSchemeChooser& getSchemeChooser() const;

private:
    SolverSchemeChooser* spObj_ = nullptr;
};

}
#endif // SIMPLEFVM_SCHEMECHOOSERMODULE_H