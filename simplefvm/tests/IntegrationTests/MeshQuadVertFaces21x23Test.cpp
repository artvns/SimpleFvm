#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "simplefvm/libQuadMeshSolver"

#include "FileReader/ReaderTxt.h"


const std::string NAME_PART = "21x23_vertFaces";


void executeCalculation4() {
    using namespace sfvm;
    
    const std::string meshFile = "./data/_mesh_TEST_" + NAME_PART;

    const double dx = 0.01;
    const double dy = 0.01;

    QmSolver fvmSolver_;
    fvmSolver_.loadMesh(meshFile, dx, dy);


    AlgorithmChooserModule algChooser_;
    algChooser_.select_SIMPLE();

    SchemeChooserModule schemeChooserModule_;
    schemeChooserModule_.select_HYBRID();

    SleSolverChooserModule sleSolverChooserModule_;
    sleSolverChooserModule_.select_EIGEN_SOLVER();

    FluidPropsModule fluidPropsModule_;
    fluidPropsModule_.setDynamicViscosity(0.001004);
    fluidPropsModule_.setDensity(998.0);

    PartTypeChooserModule partTypeChooserModule_;
    partTypeChooserModule_.set_INTERIOR("z");
    partTypeChooserModule_.set_STATIC_WALL("a");
    partTypeChooserModule_.set_STATIC_WALL("b");
    partTypeChooserModule_.set_STATIC_WALL("c");
    partTypeChooserModule_.set_STATIC_WALL("d");
    partTypeChooserModule_.set_STATIC_WALL("e");
    partTypeChooserModule_.set_STATIC_WALL("f");
    partTypeChooserModule_.set_STATIC_WALL("g");
    partTypeChooserModule_.set_MOVING_WALL("h", 0.002);
    partTypeChooserModule_.set_MOVING_WALL("i", 0.0015);
    partTypeChooserModule_.set_MOVING_WALL("j", 0.005);

    ResidualsSettingsModule residualsSettingsModule_;
    // residualsSettingsModule_.selectConsoleOutput();
    // residualsSettingsModule_.selectFileOutput("residuals");


    fvmSolver_.defineAlgorithm(algChooser_);
    fvmSolver_.defineScheme(schemeChooserModule_);
    fvmSolver_.defineSleSolver(sleSolverChooserModule_);
    fvmSolver_.defineFluidProperties(fluidPropsModule_);
    fvmSolver_.defineBoundaryConditions(partTypeChooserModule_);
    fvmSolver_.defineResidualsSettings(residualsSettingsModule_);


    fvmSolver_.startCalculation(500);
    fvmSolver_.saveFileTxt("results_" + NAME_PART);
    fvmSolver_.saveFileVtk("PolyMeshhh_" + NAME_PART);
}


namespace integr_tests {


TEST(MeshQuadVertFaces21x23Test, test_1) {
    executeCalculation4();

    ReaderTxt resultData_;
    ReaderTxt etalonData_;


    // Compare .txt files.
    resultData_.readFile("results_" + NAME_PART + ".txt");
    etalonData_.readFile("./target_data/results_etalon_" + NAME_PART + ".txt");

    for (size_t i = 0; i < resultData_.getLinesAmount(); i++) {
        ASSERT_STREQ (
            resultData_.getLine(i).c_str(), 
            etalonData_.getLine(i).c_str()
        );
    }


    // Compare .vtk files.
    resultData_.readFile("PolyMeshhh_" + NAME_PART + ".vtk");
    etalonData_.readFile("./target_data/PolyMeshhh_etalon_" + NAME_PART + ".vtk");

    for (size_t i = 0; i < resultData_.getLinesAmount(); i++) {
        ASSERT_STREQ (
            resultData_.getLine(i).c_str(), 
            etalonData_.getLine(i).c_str()
        );
    }
}

}