file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(CellsInteriorNumbering)
add_subdirectory(VelocityNumberingSets)

set(STAGGERED_MESH_PART ${STAGGERED_MESH_PART}
		${SOURCES} 
		${HEADERS}
		${CELLS_INTERIOR_NUMBERING}
		${VELOCITY_NUMBERING_SETS}
PARENT_SCOPE)