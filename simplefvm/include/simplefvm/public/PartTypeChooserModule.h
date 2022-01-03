#ifndef SIMPLEFVM_PARTTYPECHOOSERMODULE_H
#define SIMPLEFVM_PARTTYPECHOOSERMODULE_H

#include <memory>
#include <string>

#include "MSolverMacros.h"


namespace mainsolver {

class SolverPartTypeChooser;

class SFVM_API_ PartTypeChooserModule {
public:
    PartTypeChooserModule();
    ~PartTypeChooserModule();

    void set_INTERIOR(std::string partName);
    void set_MOVING_WALL(std::string partName, const double wallVelocity);
    void set_STATIC_WALL(std::string partName);

    SolverPartTypeChooser& getPartTypeChooser() const;

private:
    SolverPartTypeChooser* spObj_ = nullptr;
};

}
#endif // SIMPLEFVM_PARTTYPECHOOSERMODULE_H