file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(FIELDS_STORES ${FIELDS_STORES}
	${SOURCES} 
	${HEADERS}
PARENT_SCOPE)