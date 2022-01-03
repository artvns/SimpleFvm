project(ResultsSaver)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(SimpleSaver)
add_subdirectory(VtkSaver)

set(RESULTS_SAVER ${RESULTS_SAVER}
		${SOURCES} 
		${HEADERS}
		${SIMPLE_SAVER}
		${VTK_SAVER}
PARENT_SCOPE)