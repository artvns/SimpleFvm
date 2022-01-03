file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(StateFlags)
add_subdirectory(AdjacentCellsType)
add_subdirectory(CellNumsGlobal)
add_subdirectory(CellNumsInterior)
add_subdirectory(Fields)
add_subdirectory(MeshInformation)
add_subdirectory(MeshParameters)
add_subdirectory(ResultsData)


set(DATA_STORES_LOADER_MASKS ${DATA_STORES_LOADER_MASKS}
	${SOURCES} 
	${HEADERS}
	${STATE_FLAGS}
	${ADJACENT_CELLS_TYPE}
	${CELL_NUMS_GLOBAL}
	${CELL_NUMS_INTERIOR}
	${FIELDS}
	${MESH_INFORMATION}
	${MESH_PARAMETERS}
	${RESULTS_DATA}
PARENT_SCOPE)