#ifndef SIMPLEFVM_MESHLOADER_MESHCONTAINER_CELL_H
#define SIMPLEFVM_MESHLOADER_MESHCONTAINER_CELL_H

#include <cstddef>


namespace meshloader {

class Cell {
public:
    Cell(size_t globalNum, size_t interiorNum);
    Cell(size_t globalNum);

    size_t getGlobalNum() const;

    size_t getInteriorNum() const;
    void setInteriorNum(size_t interiorNum);

    double getValue() const;
    void setValue(double value);

    double get_dX() const;
    void set_dX(double dx);

    double get_dY() const;
    void set_dY(double dy);

private:
    size_t globalNum_ = 0;
    size_t interiorNum_ = 0;
    double value_ = 0.0;
    double dx_ = 0.0;
    double dy_ = 0.0;
};

}
#endif // SIMPLEFVM_MESHLOADER_MESHCONTAINER_CELL_H