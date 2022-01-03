#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_POINTSCONTAINER_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_POINTSCONTAINER_H

#include <cstddef>
#include <memory>
#include <vector>

#include "SaverPoint.h"


namespace resultssaver {

class PointsContainer {
private:
    using uPtrSaverPoint = std::unique_ptr<SaverPoint>;
    using uPtrSaverPointVector = std::vector<uPtrSaverPoint>;

public:
    PointsContainer();
    
    uPtrSaverPointVector& getContainer();
    uPtrSaverPoint& getPoint(size_t index);
    size_t getPointsAmount() const;

private:
    uPtrSaverPointVector pointsContainer_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_POINTSCONTAINER_H