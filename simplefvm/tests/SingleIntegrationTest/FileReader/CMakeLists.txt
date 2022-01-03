file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(FILE_READER ${FILE_READER}
        ${SOURCES} 
        ${HEADERS}

PARENT_SCOPE)