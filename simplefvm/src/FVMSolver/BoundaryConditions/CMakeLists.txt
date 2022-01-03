file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(BcParametersStores)
add_subdirectory(BcChecking)

set(BOUNDARY_CONDITIONS ${BOUNDARY_CONDITIONS}
	${SOURCES}
	${HEADERS}
	${BC_PARAMETERS_STORES}
	${BC_CHECKING}
PARENT_SCOPE)
