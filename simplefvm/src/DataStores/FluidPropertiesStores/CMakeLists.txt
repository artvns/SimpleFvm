file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(FLUID_PROPERTIES_STORES ${FLUID_PROPERTIES_STORES}
	${SOURCES} 
	${HEADERS}
PARENT_SCOPE)