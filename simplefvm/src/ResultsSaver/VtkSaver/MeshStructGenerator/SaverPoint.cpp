#include "SaverPoint.h"

namespace resultssaver {

SaverPoint::SaverPoint(size_t pointId, 
            double xCoord, 
            double yCoord) : 
                    pointId_(pointId),
                    xCoord_(xCoord),
                    yCoord_(yCoord) {

}

size_t SaverPoint::getPointId() const {
    return pointId_;
}

double SaverPoint::getCoordX() const {
    return xCoord_;
}

double SaverPoint::getCoordY() const {
    return yCoord_;
}

}