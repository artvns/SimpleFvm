file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(CELL_NUMS_INTERIOR_STORES ${CELL_NUMS_INTERIOR_STORES}
	${SOURCES} 
	${HEADERS}
PARENT_SCOPE)