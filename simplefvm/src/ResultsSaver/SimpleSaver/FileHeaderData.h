#ifndef SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_FILEHEADERDATA_H
#define SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_FILEHEADERDATA_H

#include <fstream>


namespace resultssaver {

class FileHeaderData {
public:
    FileHeaderData();

    void outputData(std::ofstream& fout);

private:

};

}
#endif // SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_FILEHEADERDATA_H