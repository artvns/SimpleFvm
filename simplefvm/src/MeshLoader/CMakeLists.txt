project(MeshLoader)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(DataStoresLoaderMasks)
add_subdirectory(CellsNumeration)
add_subdirectory(MeshTemplates)
add_subdirectory(DomainDecomposition)
add_subdirectory(SolverDataPackers)
add_subdirectory(FileReader)
add_subdirectory(MeshContainer)
add_subdirectory(LoaderDataStores)
add_subdirectory(StaggeredMeshPart)
add_subdirectory(MeshInfoExtraction)

set(MESH_LOADER ${MESH_LOADER}
		${SOURCES} 
		${HEADERS}
		${DATA_STORES_LOADER_MASKS}
		${CELLS_NUMERATION}
		${MESH_TEMPLATES}
		${DOMAIN_DECOMPOSITION}
		${SOLVER_DATA_PACKERS}
		${FILE_READER}
		${MESH_CONTAINER}
		${LOADER_DATA_STORES}
		${STAGGERED_MESH_PART}
		${MESH_INFO_EXTRACTION}
PARENT_SCOPE)