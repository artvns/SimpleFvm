#ifndef SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SAVEDRHSSTORE_H
#define SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SAVEDRHSSTORE_H

#include <cstddef>
#include <vector>


namespace fvmsolver {

class SavedRhsStore {
public:
    SavedRhsStore();

    void createArrays(const size_t size);

    double getRhs(const size_t pos) const;
    void setRhs(const size_t pos, double value);

    double get_b(const size_t pos) const;
    void set_b(const size_t pos, double value);

private:
    std::vector<double> rhs_;
    std::vector<double> b_;

    void resizeVector(std::vector<double>& vect, const size_t size);
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SAVEDRHSSTORE_H