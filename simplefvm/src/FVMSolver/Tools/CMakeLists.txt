file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(LocalAdt)
add_subdirectory(Enums)
add_subdirectory(DataSets)

set(TOOLS ${TOOLS}
		${SOURCES}
		${HEADERS}
		${LOCAL_ADT}
		${ENUMS}
		${DATA_SETS}
PARENT_SCOPE)