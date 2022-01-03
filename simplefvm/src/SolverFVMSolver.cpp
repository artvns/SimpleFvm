#include "SolverFVMSolver.h"

namespace mainsolver {

SolverFVMSolver::SolverFVMSolver(
                fvmsolver::Solver& solver,
                datastores::GlobalDataStores& dataStores) : 
                                    solver_(solver),
                                    dataStores_(dataStores) {

}

void SolverFVMSolver::startCalculation(const size_t numberOfIterations) {
    try {
        if (!dataStores_.getSolverStateFlags().isMeshLoaded) {
            throw customexceptions::PreparatoryOperationsException(
                    "Mesh file is not being loaded...");
        }
        solver_.start(numberOfIterations);
    }
    catch (const customexceptions::PreparatoryOperationsException& ex) {
        std::cerr << "Error. Cannot start calculation, ";
        std::cerr << "some preparatory operations are missed." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const customexceptions::BoundaryConditionsException& ex) {
        std::cerr << "Error. Boundary conditions problems." << '\n';
        std::cerr << ex.what() << '\n';
        ex.outputUndefinedBcNames();
    }
    catch (const customexceptions::FluidPropertiesEcxeption& ex) {
        std::cerr << "Error. Wrong value of fluid properties is being defined." << '\n';
        std::cerr << ex.what() << '\n';
        std::cerr << "Property value: " << ex.getPropertyValue() << '\n';
    }
    catch (const customexceptions::SolverSettingsException& ex) {
        std::cerr << "Error. Not all solver properties are being selected." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const customexceptions::SleSolverException& ex) {
        std::cerr << "Error. Some problems with SLE solver." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const std::bad_alloc& ex) {
        std::cerr << "Error. Cannot allocate memory." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const std::ios::ios_base::failure& ex) {
        std::cerr << "Error. Failed to write file." << '\n';
        std::cerr << ex.what() << '\n';
    }
    catch (const std::overflow_error& ex) {
        std::cerr << "Error. Invalid values were entered." << '\n';
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

}