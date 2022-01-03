file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")


add_subdirectory(Fields)
add_subdirectory(MeshInformation)
add_subdirectory(FluidProperties)
add_subdirectory(MeshParameters)
add_subdirectory(CellNumsGlobal)
add_subdirectory(CellNumsInterior)
add_subdirectory(AdjacentCellsType)
add_subdirectory(DataValidation)


set(DATA_RECIEVER ${DATA_RECIEVER}
		${SOURCES}
		${HEADERS}
		${SOLVER_FIELDS}
		${SOLVER_MESH_INFORMATION}
		${SOLVER_FLUID_PROPERTIES}
		${SOLVER_MESH_PARAMETERS}
		${SOLVER_CELL_NUMS_GLOBAL}
		${SOLVER_CELL_NUMS_INTERIOR}
		${SOLVER_ADJACENT_CELLS_TYPE}
		${DATA_VALIDATION}
PARENT_SCOPE)
