#include "PointsContainer.h"

namespace resultssaver {

PointsContainer::PointsContainer() {

}

PointsContainer::uPtrSaverPointVector& PointsContainer::getContainer() {
    return pointsContainer_;
}

PointsContainer::uPtrSaverPoint& PointsContainer::getPoint(size_t index) {
    return pointsContainer_.at(index);
}

size_t PointsContainer::getPointsAmount() const {
    return pointsContainer_.size();
}

}