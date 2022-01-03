#include "Mesh.h"

namespace meshloader {

Mesh::Mesh() {

}

void Mesh::addCell(uPtrMacroCell ptr) {
    mesh_.push_back(std::move(ptr));
}

Mesh::uPtrMacroCell& Mesh::getCell(const size_t globalNum) {
    return mesh_[findCellIndex(globalNum)];
}

Mesh::uPtrMacroCell& Mesh::getCellByIndex(const size_t index) {
    return mesh_.at(index);
}

size_t Mesh::getCellsAmount() {
    return mesh_.size();
}

void Mesh::placeCellNumIndexByGlobalCellNum() {
    cellIndexByGlobalCellNum_.resize(mesh_.size(), 0);

    for (size_t i = 0; i < mesh_.size(); i++) {
        size_t globalNum_ = mesh_[i]->getCellGlobalNum();
        cellIndexByGlobalCellNum_[globalNum_ - 1] = i;
    }
}

void Mesh::defineMeshAsLinked() {
    isLinked_ = true;
}

bool Mesh::isLinked() {
    return isLinked_;
}

Mesh::uPtrMacroCell& Mesh::getAdjCellW(const size_t globalNum) {
    return mesh_[findCellIndex(globalNum)]->getMacroCellW();
}

Mesh::uPtrMacroCell& Mesh::getAdjCellE(const size_t globalNum) {
    return mesh_[findCellIndex(globalNum)]->getMacroCellE();
}

Mesh::uPtrMacroCell& Mesh::getAdjCellN(const size_t globalNum) {
    return mesh_[findCellIndex(globalNum)]->getMacroCellN();
}

Mesh::uPtrMacroCell& Mesh::getAdjCellS(const size_t globalNum) {
    return mesh_[findCellIndex(globalNum)]->getMacroCellS();
}

size_t Mesh::findCellIndex(const size_t globalNum) {
    return cellIndexByGlobalCellNum_[globalNum - 1];
}

}