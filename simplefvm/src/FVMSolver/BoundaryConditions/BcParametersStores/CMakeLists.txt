file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(BC_PARAMETERS_STORES ${BC_PARAMETERS_STORES} 
	${SOURCES} 
	${HEADERS}
PARENT_SCOPE)