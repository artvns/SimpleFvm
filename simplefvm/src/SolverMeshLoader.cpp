#include "SolverMeshLoader.h"

namespace mainsolver {

SolverMeshLoader::SolverMeshLoader(
                datastores::GlobalDataStores& dataStores) : 
                                    dataStores_(dataStores) {

}

void SolverMeshLoader::loadMesh(const std::string fileName, 
                                        const double dx, const double dy) {
    try {
        if (0 >= dx || 0 >= dy) {
            throw std::underflow_error(
                        "dx or dy values are less than or equal to zero...");
        }

        meshloader::Loader loader_(dataStores_);
        loader_.loadDataFromFile(fileName, dx, dy);
    }
    catch (const customexceptions::MeshLoadStateException& ex) {
        std::cerr << "Error. Failed to load mesh." << '\n';
        std::cerr << ex.what() << '\n';
        std::cerr << "line number: "  << ex.getLineNumber() << '\n';
        std::cerr << "column number: "  << ex.getColumnNumber() << '\n';
    }
    catch (const customexceptions::DomainPartsException& ex) {
        std::cerr << "Error. Failed to extract part name during ";
        std::cerr << "mesh loading." << '\n';
        std::cerr << ex.what() << '\n';
        ex.outputProblemPartNames();
    }
    catch (const std::bad_alloc& ex) {
        std::cerr << "Error. Cannot allocate memory." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const std::ios::ios_base::failure& ex) {
        std::cerr << "Error. Cannot find or open file to read." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const std::range_error& ex) {
        std::cerr << "Error. Value is out of range." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const std::underflow_error& ex) {
        std::cerr << "Error. Invalid values were entered." << '\n';
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

std::vector<std::string>& SolverMeshLoader::getBcNamesVector() {
    return dataStores_.getMeshInfoStoreP().getBcNamesVector();
}

}