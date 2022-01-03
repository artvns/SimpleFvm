file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(SettingsComponents)
add_subdirectory(SolverSettingsValidation)

set(SOLVER_SETTINGS ${SOLVER_SETTINGS}
	${SOURCES}
	${HEADERS}
	${SETTINGS_COMPONENTS}
	${SOLVER_SETTINGS_VALIDATION}
PARENT_SCOPE)
