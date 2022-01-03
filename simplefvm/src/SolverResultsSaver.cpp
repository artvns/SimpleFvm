#include "SolverResultsSaver.h"

namespace mainsolver {


SolverResultsSaver::SolverResultsSaver(
                datastores::GlobalDataStores& dataStores) : 
                                    dataStores_(dataStores) {

}

void SolverResultsSaver::saveFileVtk(const std::string fileName) {
    saveFile(fileName, SAVE_FILE_TYPE_VTK);
}

void SolverResultsSaver::saveFileTxt(const std::string fileName) {
    saveFile(fileName, SAVE_FILE_TYPE_TXT);
}

void SolverResultsSaver::saveFile(const std::string fileName, 
                                    const SaveFileType fileType) {

    try {
        resultssaver::Saver saver_(
            dataStores_.getFieldsStore(), 
            dataStores_.getMeshParametersStoreP(),
            dataStores_.getMeshBuildingStore()
        );
        if (SAVE_FILE_TYPE_VTK == fileType) {
            saver_.saveDataVtk(fileName);
        }
        else if (SAVE_FILE_TYPE_TXT == fileType) {
            saver_.saveDataTxt(fileName);
        }
    }
    catch (const std::bad_alloc& ex) {
        std::cerr << "Error. Cannot allocate memory." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const std::ios::ios_base::failure& ex) {
        std::cerr << "Error. Failed to write file." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const std::exception& ex) {
        std::cerr << "Error. Standard exception." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (...) {
        std::cerr << "Error. Unknown error happened." << '\n';
    } 
}

}