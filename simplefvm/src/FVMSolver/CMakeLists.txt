project(FVMSolver)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(SolverSettings)
add_subdirectory(MeshInformation)
add_subdirectory(MathToolsReciever)
add_subdirectory(SolverDataStores)
add_subdirectory(CoeffsPartsCommon)
add_subdirectory(CoeffsPartsVelocity)
add_subdirectory(CoeffsPartsPressure)
add_subdirectory(CoeffsCalculators)
add_subdirectory(MatrixBuilder)
add_subdirectory(Sle)
add_subdirectory(BoundaryConditions)
add_subdirectory(DataReciever)
add_subdirectory(SolutionAlgorithms)
add_subdirectory(FieldsCorrection)
add_subdirectory(ResidualsCalculation)
add_subdirectory(FieldsInterpolation)
add_subdirectory(Tools)
add_subdirectory(ResidualsOutput)

set(FVM_SOLVER ${FVM_SOLVER}
		${SOURCES} 
		${HEADERS}
		${SOLVER_SETTINGS}
		${MESH_INFORMATION}
		${MATH_TOOLS_RECIEVER}
		${SOLVER_DATA_STORES}
		${COEFFS_PARTS_COMMON}
		${COEFFS_PARTS_VELOCITY}
		${COEFFS_PARTS_PRESSURE}
		${COEFFS_CALCULATORS}
		${SLE}
		${MATRIX_BUILDER}
		${BOUNDARY_CONDITIONS}
		${DATA_RECIEVER}
		${SOLUTION_ALGORITHMS}
		${FIELDS_CORRECTION}
		${RESIDUALS_CALCULATION}
		${FIELDS_INTERPOLATION}
		${TOOLS}
		${RESIDUALS_OUTPUT}
PARENT_SCOPE)