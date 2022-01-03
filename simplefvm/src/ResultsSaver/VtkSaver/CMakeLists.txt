file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(RecievedData)
add_subdirectory(DataPackers)
add_subdirectory(MeshStructGenerator)

set(VTK_SAVER ${VTK_SAVER}
	${SOURCES}
	${HEADERS}
        ${RECIEVED_DATA}
        ${DATA_PACKERS}
        ${MESH_STRUCT_GENERATOR}
PARENT_SCOPE)

