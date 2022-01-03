#ifndef SIMPLEFVM_MESHLOADER_MESHCONTAINER_MACROCELL_H
#define SIMPLEFVM_MESHLOADER_MESHCONTAINER_MACROCELL_H

#include <cstddef>
#include <memory>

#include "Cell.h"


namespace meshloader {
    
class MacroCell {
private:
    using uPtrMacroCell = std::unique_ptr<MacroCell>;

public:
    MacroCell(const size_t globalNum, const size_t interiorNum);
    ~MacroCell();

    uPtrMacroCell& getMacroCellW();
    void setMacroCellW(uPtrMacroCell& ptr);

    uPtrMacroCell& getMacroCellE();
    void setMacroCellE(uPtrMacroCell& ptr);

    uPtrMacroCell& getMacroCellN();
    void setMacroCellN(uPtrMacroCell& ptr);
    
    uPtrMacroCell& getMacroCellS();
    void setMacroCellS(uPtrMacroCell& ptr);

    Cell& getCellU();
    Cell& getCellV();
    Cell& getCellP();

    void defineInteriorType();
    void defineGhostType();

    size_t getCellGlobalNum();
    bool isGhostCell();

private:
    Cell uCellW_;
    Cell vCellS_;
    Cell pCellP_;

    uPtrMacroCell* pCellW_ = nullptr;
    uPtrMacroCell* pCellE_ = nullptr;
    uPtrMacroCell* pCellN_ = nullptr;
    uPtrMacroCell* pCellS_ = nullptr;

    const size_t cellNumGlobal_ = 0;
    const size_t cellNumInterior_ = 0;
    bool isGhostCell_ = false;
};

}
#endif // SIMPLEFVM_MESHLOADER_MESHCONTAINER_MACROCELL_H