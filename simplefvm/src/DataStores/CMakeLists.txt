project(DataStores)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(Adt)
add_subdirectory(AdjCellNumsGlobalStores)
add_subdirectory(AdjCellsTypeStores)
add_subdirectory(CellNumsGlobalStores)
add_subdirectory(CellNumsInteriorStores)
add_subdirectory(FieldsStores)
add_subdirectory(FluidPropertiesStores)
add_subdirectory(MeshParametersStores)
add_subdirectory(MeshInformationStore)
add_subdirectory(ResultsDataStores)
add_subdirectory(StateFlags)

set(DATA_STORES ${DATA_STORES}
		${SOURCES} 
		${HEADERS}
		${ADT}
		${ADJ_CELL_NUMS_GLOBAL_STORES}
		${ADJ_CELLS_TYPES_TORES}
		${CELL_NUMS_GLOBAL_STORES}
		${CELL_NUMS_INTERIOR_STORES}
		${FIELDS_STORES}
		${FLUID_PROPERTIES_STORES}
		${MESH_PARAMETERS_STORES}
		${MESH_INFORMATION_STORE}
		${RESULTS_DATA_STORES}
		${STATE_FLAGS}
PARENT_SCOPE)