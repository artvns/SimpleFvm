#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_SAVERPOINT_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_SAVERPOINT_H

#include <cstddef>


namespace resultssaver {

class SaverPoint {
public:
    SaverPoint(size_t pointId, double xCoord, double yCoord);

    size_t getPointId() const;

    double getCoordX() const;
    double getCoordY() const;

private:
    size_t pointId_ = 0;
    double xCoord_ = 0.0;
    double yCoord_ = 0.0;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_MESHSTRUCTGENERATOR_SAVERPOINT_H