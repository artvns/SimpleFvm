#include "DataDefaultIter2.h"

namespace commoninitdata {

DataDefaultIter2::DataDefaultIter2() {

}


void DataDefaultIter2::initializeFluid() {
    fluidProps_.initializeProps();
}


void DataDefaultIter2::initializeCoeffs_de() {
    coeffsDeIterations_.createCoeffsCalculators();
}


void DataDefaultIter2::initializeFields() {
    fieldsIterations_.createFields();
}


void DataDefaultIter2::initializeMeshData() {
    meshParams_.createMeshData();
}


void DataDefaultIter2::initializeCalculatedScalars() {
    calcScalarsIterations_.createScalars();
}


FluidProps_DefaultIter2& DataDefaultIter2::getFluidProps() {
    return fluidProps_;
}


MeshParams_DefaultIter2& DataDefaultIter2::getMeshParams() {
    return meshParams_;
}


Fields_DefaultIter2& DataDefaultIter2::getFieldsIterations() {
    return fieldsIterations_;
}


CoeffsDe_DefaultIter2& DataDefaultIter2::getCoeffsDeIterations() {
    return coeffsDeIterations_;
}


CalcedScalars_DefaultIter2& DataDefaultIter2::getCalcScalarsIterations() {
    return calcScalarsIterations_;
}

}