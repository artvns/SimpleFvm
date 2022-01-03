#include "DataDefaultIter1.h"

namespace commoninitdata {

DataDefaultIter1::DataDefaultIter1() {

}


void DataDefaultIter1::initializeFluid() {
    fluidProps_.initializeProps();
}


void DataDefaultIter1::initializeCoeffs_de() {
    coeffsDeIterations_.createCoeffsCalculators();
}


void DataDefaultIter1::initializeFields() {
    fieldsIterations_.createFields();
}


void DataDefaultIter1::initializeMeshData() {
    meshParams_.createMeshData();
}


void DataDefaultIter1::initializeCalculatedScalars() {
    calcScalarsIterations_.createScalars();
}


FluidProps_DefaultIter1& DataDefaultIter1::getFluidProps() {
    return fluidProps_;
}


MeshParams_DefaultIter1& DataDefaultIter1::getMeshParams() {
    return meshParams_;
}


Fields_DefaultIter1& DataDefaultIter1::getFieldsIterations() {
    return fieldsIterations_;
}


CoeffsDe_DefaultIter1& DataDefaultIter1::getCoeffsDeIterations() {
    return coeffsDeIterations_;
}


CalcedScalars_DefaultIter1& DataDefaultIter1::getCalcScalarsIterations() {
    return calcScalarsIterations_;
}

}