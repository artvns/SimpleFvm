file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(FileChecker)

set(FILE_READER ${FILE_READER}
        ${SOURCES} 
        ${HEADERS}
        ${FILE_CHECKER}
PARENT_SCOPE)