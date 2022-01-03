#include "QmSolver.h"

#include "FvmSolver.h"

#include <iostream>


namespace mainsolver {

QmSolver::QmSolver() : spFvmSolver_(new FvmSolver()) {

}

QmSolver::~QmSolver() {
   delete spFvmSolver_;
   spFvmSolver_ = nullptr;
}


void QmSolver::defineAlgorithm(const AlgorithmChooserModule& algirithm) {
   spFvmSolver_->setAlgorithm(algirithm.getAlgorithmChooser());
}


void QmSolver::defineFluidProperties(const FluidPropsModule& fluidProperties) {
   spFvmSolver_->setFluidProps(fluidProperties.getFluidPropsDefiner());
}


void QmSolver::defineScheme(const SchemeChooserModule& scheme) {
   spFvmSolver_->setScheme(scheme.getSchemeChooser());
}


void QmSolver::defineSleSolver(const SleSolverChooserModule& sleSolver) {
   spFvmSolver_->setSleSolver(sleSolver.getSleSolverChooser());
}


void QmSolver::defineBoundaryConditions(
                        const PartTypeChooserModule& partTypes) {
   spFvmSolver_->setBoundaryConditions(partTypes.getPartTypeChooser());
}


void QmSolver::defineResidualsSettings(
                        const ResidualsSettingsModule& residualsSettings) {
   spFvmSolver_->setResidualsSettings(
      residualsSettings.getResidsSettingsDefiner());
}



std::vector<std::string>& QmSolver::getBoundaryConditionsNames() {
   return spFvmSolver_->getSolverMeshLoader().getBcNamesVector();
}


void QmSolver::loadMesh(const std::string meshFileName, 
                                       const double dx, const double dy) {
   spFvmSolver_->getSolverMeshLoader().loadMesh(meshFileName, dx, dy);
}


void QmSolver::startCalculation(const size_t numberOfIterations) {
   spFvmSolver_->getSolverFVMSolver().startCalculation(numberOfIterations);
}


void QmSolver::saveFileTxt(const std::string resultFileName) {
   spFvmSolver_->getSolverResultsSaver().saveFileTxt(resultFileName);
}


void QmSolver::saveFileVtk(const std::string resultFileName) {
   spFvmSolver_->getSolverResultsSaver().saveFileVtk(resultFileName);
}

}