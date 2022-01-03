#ifndef SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_BASICSOLVERVARIABLES_H
#define SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_BASICSOLVERVARIABLES_H

#include <cstddef>
#include <memory>
#include <string>


namespace fvmsolver {

class BasicSolverVariables {
public:
    BasicSolverVariables();

    void setNumberOfIterations(const size_t iterations);
    size_t getNumberOfIterations() const;

    void setDxDyValue(const double value);
    double getDxDyValue() const;

    void setResidualsFullFileName(const std::string fullFileName);
    std::string getResidualsFullFileName() const;

private:
    size_t numberOfIterations_ = 0;
    double dimentionDxDy_ = 0.0;
    std::string fullFileName_ = "";
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERSETTINGS_BASICSOLVERVARIABLES_H