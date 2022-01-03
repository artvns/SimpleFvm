#ifndef SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_COEFFSCALCULATORSSTORE_H
#define SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_COEFFSCALCULATORSSTORE_H

#include <cstddef>
#include <vector>


namespace fvmsolver {

class CoeffsCalculatorsStore {
public:
    CoeffsCalculatorsStore();

    void createArrays(const size_t uSize, const size_t vSize);

    double get_deU(const size_t pos) const;
    void   set_deU(const size_t pos, double value);

    double get_deV(const size_t pos) const;
    void   set_deV(const size_t pos, double value);

private:
    std::vector<double> deU_;
    std::vector<double> deV_;

    void resizeVector(std::vector<double>& vect, const size_t size);
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_COEFFSCALCULATORSSTORE_H