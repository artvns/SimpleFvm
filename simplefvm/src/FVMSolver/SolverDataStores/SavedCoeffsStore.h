#ifndef SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SAVEDCOEFFSSTORE_H
#define SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SAVEDCOEFFSSTORE_H

#include <cstddef>
#include <vector>


namespace fvmsolver {

class SavedCoeffsStore {
public:
    SavedCoeffsStore();

    void createArrays(const size_t size);

    std::vector<double>& getAp();
    std::vector<double>& getAw();
    std::vector<double>& getAe();
    std::vector<double>& getAn();
    std::vector<double>& getAs();

private:
    std::vector<double> Ap_;
    std::vector<double> Aw_;
    std::vector<double> Ae_;
    std::vector<double> An_;
    std::vector<double> As_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SAVEDCOEFFSSTORE_H