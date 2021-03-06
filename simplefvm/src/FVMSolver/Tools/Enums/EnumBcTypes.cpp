#ifndef SIMPLEFVM_FVMSOLVER_TOOLS_ENUMS_ENUMBCTYPES_H
#define SIMPLEFVM_FVMSOLVER_TOOLS_ENUMS_ENUMBCTYPES_H

namespace fvmsolver {

enum EnumBcTypes {
	BC_TYPES_VELOCITY_INLET,
	BC_TYPES_PRESSURE_INLET,
	BC_TYPES_PRESSURE_OUTLET,
	BC_TYPES_MOVING_WALL,
	BC_TYPES_STATIC_WALL
};

}
#endif // SIMPLEFVM_FVMSOLVER_TOOLS_ENUMS_ENUMBCTYPES_H