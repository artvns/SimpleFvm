file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(ADT ${ADT}
	${SOURCES} 
	${HEADERS}
PARENT_SCOPE)