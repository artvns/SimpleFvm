#include "CellsGenerator.h"

namespace resultssaver {

CellsGenerator::CellsGenerator() {

}

void CellsGenerator::createCellsAndPoints(
                        const MeshInformation& meshInfo,
                        const CellsInfo& cellsInfo,
                        std::vector<uPtrSaverPoint>& points,
                        std::vector<uPtrSaverCell>& cells) {

    cells.resize(meshInfo.getCellsAmount());

    size_t pointId = 0;
    size_t cellNum = 0;

    double xCoord_ = 0.0;
    double yCoord_ = 0.0;
    
    double dx_ = meshInfo.get_dX();
    double dy_ = meshInfo.get_dY();


    for (size_t i = 0; i < meshInfo.getDimentionY(); i++) {
        xCoord_ = 0.0;
        for (size_t j = 0; j < meshInfo.getDimentionX(); j++) {

            size_t i_modyfied = meshInfo.getDimentionY() - 1 - i;

            // If current cell exists.
            if (0 != cellsInfo.getType(i_modyfied + 1, j + 1)) {
                size_t pointId_0_ = 0;
                size_t pointId_1_ = 0;
                size_t pointId_2_ = 0;
                size_t pointId_3_ = 0;

                bool isSaverCellExistW_ = false;
                bool isSaverCellExistS_ = false;
                bool isSaverCellExistSW_ = false;
                bool isSaverCellExistSE_ = false;

                // Scan which adjacent cells exist.
                if (!(0 == cellsInfo.getType(i_modyfied + 1, j))) {
                    isSaverCellExistW_ = true;
                }
                if (!(0 == cellsInfo.getType(i_modyfied + 2, j + 1))) {
                    isSaverCellExistS_ = true;
                }
                if (!(0 == cellsInfo.getType(i_modyfied + 2, j))) {
                    isSaverCellExistSW_ = true;
                }
                if (!(0 == cellsInfo.getType(i_modyfied + 2, j + 2))) {
                    isSaverCellExistSE_ = true;
                }

                double point0_x_ = xCoord_;
                double point0_y_ = yCoord_;
                double point1_x_ = xCoord_ + dx_;
                double point1_y_ = yCoord_;
                double point2_x_ = xCoord_ + dx_;
                double point2_y_ = yCoord_ + dy_;
                double point3_x_ = xCoord_;
                double point3_y_ = yCoord_ + dy_;

                // There are no cells around.
                if (!isSaverCellExistW_ & !isSaverCellExistS_ & !isSaverCellExistSW_ & !isSaverCellExistSE_) {
                        pointId_0_ = pointId++;
                        pointId_1_ = pointId++;
                        pointId_2_ = pointId++;
                        pointId_3_ = pointId++;

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_0_, point0_x_, point0_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_1_, point1_x_, point1_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_3_, point3_x_, point3_y_))));
                }
                // There is only cell on W.
                else if (isSaverCellExistW_ & !isSaverCellExistS_ & !isSaverCellExistSW_ & !isSaverCellExistSE_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied, j - 1))->getPointId_1();
                        pointId_1_ = pointId++;
                        pointId_2_ = pointId++;
                        pointId_3_ = cells.at(cellsInfo.getNum(i_modyfied, j - 1))->getPointId_2();

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_1_, point1_x_, point1_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                }
                // There is only cell on S.
                else if (!isSaverCellExistW_ & isSaverCellExistS_ & !isSaverCellExistSW_ & !isSaverCellExistSE_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_3();
                        pointId_1_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_2();
                        pointId_2_ = pointId++;
                        pointId_3_ = pointId++;

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_3_, point3_x_, point3_y_))));
                }
                // There is only cell on SW.
                else if (!isSaverCellExistW_ & !isSaverCellExistS_ & isSaverCellExistSW_ & !isSaverCellExistSE_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j - 1))->getPointId_2();
                        pointId_1_ = pointId++;
                        pointId_2_ = pointId++;
                        pointId_3_ = pointId++;

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_1_, point1_x_, point1_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_3_, point3_x_, point3_y_))));
                }
                // There is only cell on SE.
                else if (!isSaverCellExistW_ & !isSaverCellExistS_ & !isSaverCellExistSW_ & isSaverCellExistSE_) {
                        pointId_0_ = pointId++;
                        pointId_1_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j + 1))->getPointId_3();
                        pointId_2_ = pointId++;
                        pointId_3_ = pointId++;

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_0_, point0_x_, point0_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_3_, point3_x_, point3_y_))));
                }
                // There is only cell on W and S.
                else if (isSaverCellExistW_ & isSaverCellExistS_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied, j - 1))->getPointId_1();
                        pointId_1_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_2();
                        pointId_2_ = pointId++;
                        pointId_3_ = cells.at(cellsInfo.getNum(i_modyfied, j - 1))->getPointId_2();

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                }
                // There is only cell on W and SE.
                else if (isSaverCellExistW_ & isSaverCellExistSE_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied, j - 1))->getPointId_1();
                        pointId_1_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j + 1))->getPointId_3();
                        pointId_2_ = pointId++;
                        pointId_3_ = cells.at(cellsInfo.getNum(i_modyfied, j - 1))->getPointId_2();

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                }
                // There is only cell on the SW and SE.
                else if (!isSaverCellExistW_ & !isSaverCellExistS_ & isSaverCellExistSW_ & isSaverCellExistSE_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j - 1))->getPointId_2();
                        pointId_1_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j + 1))->getPointId_3();
                        pointId_2_ = pointId++;
                        pointId_3_ = pointId++;

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_3_, point3_x_, point3_y_))));
                }
                // There is only cell on W and SW.
                else if (isSaverCellExistW_ & !isSaverCellExistS_ & isSaverCellExistSW_ & !isSaverCellExistSE_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied, j - 1))->getPointId_1();
                        pointId_1_ = pointId++;
                        pointId_2_ = pointId++;
                        pointId_3_ = cells.at(cellsInfo.getNum(i_modyfied, j - 1))->getPointId_2();

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_1_, point1_x_, point1_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                }
                // There is only cell on S and SW.
                else if (!isSaverCellExistW_ & isSaverCellExistS_ & isSaverCellExistSW_ & !isSaverCellExistSE_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_3();
                        pointId_1_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_2();
                        pointId_2_ = pointId++;
                        pointId_3_ = pointId++;

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_3_, point3_x_, point3_y_))));
                }
                // There are only cells W and S, the rest don’t matter.
                else if (isSaverCellExistS_ & isSaverCellExistSE_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_3();
                        pointId_1_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_2();
                        pointId_2_ = pointId++;
                        pointId_3_ = pointId++;

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_3_, point3_x_, point3_y_))));
                }
                // There is only cell S, W is absent, the rest don’t matter.
                else if (!isSaverCellExistW_ & isSaverCellExistS_) {
                        pointId_0_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_3();
                        pointId_1_ = cells.at(cellsInfo.getNum(i_modyfied + 1, j))->getPointId_2();
                        pointId_2_ = pointId++;
                        pointId_3_ = pointId++;

                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_2_, point2_x_, point2_y_))));
                        points.push_back(std::move(uPtrSaverPoint(new SaverPoint(pointId_3_, point3_x_, point3_y_))));
                }
                
                cellNum = cellsInfo.getNum(i_modyfied, j);
                cells[cellNum] = std::move(uPtrSaverCell(new SaverCell(cellNum, pointId_0_, pointId_1_, pointId_2_, pointId_3_)));
            }
            xCoord_ += dx_;
        }
        yCoord_ += dy_;
    }
}

}