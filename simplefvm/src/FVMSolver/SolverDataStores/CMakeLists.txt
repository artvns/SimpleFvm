file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(SOLVER_DATA_STORES ${SOLVER_DATA_STORES}
		${SOURCES}
		${HEADERS}
PARENT_SCOPE)