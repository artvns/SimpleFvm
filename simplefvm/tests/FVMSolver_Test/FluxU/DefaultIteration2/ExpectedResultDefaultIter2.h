#ifndef SIMPLEFVM_FVMSOLVERTEST_FLUXU_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_FLUXU_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H

#include <cstddef>
#include <vector>


namespace flux_u {

class ExpectedResultDefaultIter2 {
public:
    ExpectedResultDefaultIter2();

    double getFw(size_t step);
    double getFe(size_t step);
    double getFn(size_t step);
    double getFs(size_t step);

private:
    std::vector<double> Fw_;
    std::vector<double> Fe_;
    std::vector<double> Fn_;
    std::vector<double> Fs_;

    void createResVector();
    void addDataRow(size_t step, double Fw_, double Fe_, double Fn_, double Fs_);
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_FLUXU_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H