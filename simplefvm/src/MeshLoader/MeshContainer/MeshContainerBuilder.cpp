#include "MeshContainerBuilder.h"

namespace meshloader {

MeshContainerBuilder::MeshContainerBuilder(
            Mesh& meshContainer, 
            NumsMatrix& interiorNumsMatrixP,
            NumsMatrix& globalNumsMatrixP) :
                                meshContainer_(meshContainer),
                                interiorNumsMatrixP_(interiorNumsMatrixP),
                                globalNumsMatrixP_(globalNumsMatrixP) {

}

void MeshContainerBuilder::buildMesh() {
    maxLines_ = globalNumsMatrixP_.getRowsAmount();
    maxCols_  = globalNumsMatrixP_.getColsAmount();

    fillMesh();
    linkMeshCells();
    
    std::cout << '\n';
    coutText_GREEN("<--- Mesh is created --->");
    std::cout << '\n';
}

void MeshContainerBuilder::fillMesh() {
    size_t globalCellNum_ = 0;
    size_t interiorCellNum_ = 0;

    uPtrMacroCell pMacroCell_ = nullptr;

    for (size_t i = 0; i < maxLines_; i++) {
        for (size_t j = 0; j < maxCols_; j++) {

            globalCellNum_   = globalNumsMatrixP_.getValue(i, j);
            interiorCellNum_ = interiorNumsMatrixP_.getValue(i, j);

            if((0 != globalCellNum_) && (0 != interiorCellNum_)) {
                pMacroCell_ = uPtrMacroCell(
                    new MacroCell(globalCellNum_, interiorCellNum_));
                pMacroCell_->defineInteriorType();
                meshContainer_.addCell(std::move(pMacroCell_));
            }
            else if((0 != globalCellNum_) && (0 == interiorCellNum_)) {
                pMacroCell_ = uPtrMacroCell(
                    new MacroCell(globalCellNum_, interiorCellNum_));
                pMacroCell_->defineGhostType();
                meshContainer_.addCell(std::move(pMacroCell_));
            }
        }
    }

    meshContainer_.placeCellNumIndexByGlobalCellNum();
}

void MeshContainerBuilder::linkMeshCells() {
    size_t cellNum_ = 0;
    size_t adjCellNumW_ = 0;
    size_t adjCellNumE_ = 0;
    size_t adjCellNumN_ = 0;
    size_t adjCellNumS_ = 0;

    for (size_t i = 0; i < maxLines_; i++) {
        for (size_t j = 0; j < maxCols_; j++) {

            if (0 != globalNumsMatrixP_.getValue(i, j)) {
                cellNum_ = globalNumsMatrixP_.getValue(i, j);
                if (!meshContainer_.getCell(cellNum_)->isGhostCell()) {
                    adjCellNumW_ = globalNumsMatrixP_.getValue(i, j - 1);
                    adjCellNumE_ = globalNumsMatrixP_.getValue(i, j + 1);
                    adjCellNumN_ = globalNumsMatrixP_.getValue(i - 1, j);
                    adjCellNumS_ = globalNumsMatrixP_.getValue(i + 1, j);

                    meshContainer_.getCell(cellNum_)->setMacroCellW(
                        meshContainer_.getCell(adjCellNumW_));
                    meshContainer_.getCell(cellNum_)->setMacroCellE(
                        meshContainer_.getCell(adjCellNumE_));
                    meshContainer_.getCell(cellNum_)->setMacroCellN(
                        meshContainer_.getCell(adjCellNumN_));
                    meshContainer_.getCell(cellNum_)->setMacroCellS(
                        meshContainer_.getCell(adjCellNumS_));
                }
            }
        }
    }

    meshContainer_.defineMeshAsLinked();    // Indicating that links between grid cells are established.
}
    
}