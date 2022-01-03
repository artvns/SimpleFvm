#ifndef SIMPLEFVM_RESULTSSAVER_I_RESULTSSAVER_H
#define SIMPLEFVM_RESULTSSAVER_I_RESULTSSAVER_H

#include "string"

namespace resultssaver {

class IResultsSaver {
public:
    virtual void saveData(const std::string fileName) = 0;

    virtual ~IResultsSaver() {};
};

}
#endif // SIMPLEFVM_RESULTSSAVER_I_RESULTSSAVER_H