#ifndef SIMPLEFVM_SOLVERRESULTSSAVER_H
#define SIMPLEFVM_SOLVERRESULTSSAVER_H

#include <string>
#include <stdexcept>

#include "DataStores/GlobalDataStores.h"
#include "ResultsSaver/Saver.h"


namespace mainsolver {

enum SaveFileType {
	SAVE_FILE_TYPE_VTK,
	SAVE_FILE_TYPE_TXT
};

class SolverResultsSaver {
public:
    SolverResultsSaver(datastores::GlobalDataStores& dataStores);

    void saveFileVtk(const std::string fileName);
    void saveFileTxt(const std::string fileName);

private:
    datastores::GlobalDataStores& dataStores_;

    void saveFile(const std::string fileName, const SaveFileType fileType);
};

}
#endif // SIMPLEFVM_SOLVERRESULTSSAVER_H