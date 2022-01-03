#ifndef SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONV_DEFAULTITERATION1_EXPECTEDRESULTDEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONV_DEFAULTITERATION1_EXPECTEDRESULTDEFAULTITER1_H

#include <cstddef>
#include <vector>


namespace diffusion_v {

class ExpectedResultDefaultIter1 {
public:
    ExpectedResultDefaultIter1();

    double getDw(size_t step);
    double getDe(size_t step);
    double getDn(size_t step);
    double getDs(size_t step);

private:
    std::vector<double> Dw_;
    std::vector<double> De_;
    std::vector<double> Dn_;
    std::vector<double> Ds_;

    void createResVector();
    void addDataRow(size_t step, double Dw, double De, double Dn, double Ds);
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_DIFFUSIONV_DEFAULTITERATION1_EXPECTEDRESULTDEFAULTITER1_H