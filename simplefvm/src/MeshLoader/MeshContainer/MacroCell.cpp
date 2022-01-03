#include "MacroCell.h"

namespace meshloader {

MacroCell::MacroCell(
                const size_t globalNum, 
                const size_t interiorNum) : 
                                uCellW_(globalNum),
                                vCellS_(globalNum),
                                pCellP_(globalNum, interiorNum),
                                cellNumGlobal_(globalNum),
                                cellNumInterior_(interiorNum) {

}

MacroCell::~MacroCell() {
    pCellW_ = nullptr;
    pCellE_ = nullptr;
    pCellN_ = nullptr;
    pCellS_ = nullptr;
}

MacroCell::uPtrMacroCell& MacroCell::getMacroCellW() {
    return *pCellW_;
}
void MacroCell::setMacroCellW(uPtrMacroCell& ptr) {
    pCellW_ = &ptr;
}

MacroCell::uPtrMacroCell& MacroCell::getMacroCellE() {
    return *pCellE_;
}

void MacroCell::setMacroCellE(uPtrMacroCell& ptr) {
    pCellE_ = &ptr;
}

MacroCell::uPtrMacroCell& MacroCell::getMacroCellN() {
    return *pCellN_;
}

void MacroCell::setMacroCellN(uPtrMacroCell& ptr) {
    pCellN_ = &ptr;
}

MacroCell::uPtrMacroCell& MacroCell::getMacroCellS() {
    return *pCellS_;
}

void MacroCell::setMacroCellS(uPtrMacroCell& ptr) {
    pCellS_ = &ptr;
}

Cell& MacroCell::getCellU() {
    return uCellW_;
}

Cell& MacroCell::getCellV() {
    return vCellS_;
}

Cell& MacroCell::getCellP() {
    return pCellP_;
}

bool MacroCell::isGhostCell() {
    return isGhostCell_;
}

size_t MacroCell::getCellGlobalNum() {
    return cellNumGlobal_;
}

void MacroCell::defineInteriorType() {
    isGhostCell_ = false;
}

void MacroCell::defineGhostType() {
    isGhostCell_ = true;
}

}