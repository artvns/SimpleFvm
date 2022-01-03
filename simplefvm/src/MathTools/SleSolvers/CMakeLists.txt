file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(EigenLib)

set(SLE_SOLVERS ${SLE_SOLVERS}
		${SOURCES} 
		${HEADERS}
		${EIGEN_LIB}
PARENT_SCOPE)