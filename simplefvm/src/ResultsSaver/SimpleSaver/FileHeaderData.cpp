#include "FileHeaderData.h"

namespace resultssaver {

FileHeaderData::FileHeaderData() {

}

void FileHeaderData::outputData(std::ofstream& fout) {
    fout << "__FileHeaderData__" << std::endl;
}

}