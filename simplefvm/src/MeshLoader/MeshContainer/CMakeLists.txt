file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(MESH_CONTAINER ${MESH_CONTAINER}
	${SOURCES} 
	${HEADERS}
PARENT_SCOPE)