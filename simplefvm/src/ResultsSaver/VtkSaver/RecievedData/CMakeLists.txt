file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(RECIEVED_DATA ${RECIEVED_DATA}
	${SOURCES} 
	${HEADERS}
PARENT_SCOPE)
