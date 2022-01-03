#ifndef SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_PARTSTYPEINFO_H
#define SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_PARTSTYPEINFO_H

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>

#include "../Tools/LocalAdt/MapAdt.cpp"


namespace fvmsolver {

enum EnumDomainPartType {
    PART_TYPE_INTERIOR,
	PART_TYPE_VELOCITY_INLET,
	PART_TYPE_PRESSURE_INLET,
	PART_TYPE_PRESSURE_OUTLET,
	PART_TYPE_MOVING_WALL,
	PART_TYPE_STATIC_WALL
};


class PartsTypeInfo {
public:
    PartsTypeInfo();

    std::vector<std::string>& getAllBcDefinedPartNames();
    std::string getDefinedPartName(size_t index);
    size_t getDefinedPartNamesAmount();


    void defineTypeAsInterior      (const std::string name);
    void defineTypeAsVelocityInlet (const std::string name);
    void defineTypeAsPressureInlet (const std::string name);
    void defineTypeAsPressureOutlet(const std::string name);
    void defineTypeAsMovingWall    (const std::string name);
    void defineTypeAsStaticWall    (const std::string name);

    bool isInterior      (const std::string name);
    bool isVelocityInlet (const std::string name);
    bool isPressureInlet (const std::string name);
    bool isPressureOutlet(const std::string name);
    bool isMovingWall    (const std::string name);
    bool isStaticWall    (const std::string name);

    // std::vector<std::string> getInteriorPartNames();
    // std::vector<std::string> getBoundaryPartNames();

private:
    MapAdt<EnumDomainPartType> partTypeMap_;
    std::vector<std::string> interiorPartNames_;
    std::vector<std::string> boundaryPartNames_;
    std::vector<std::string> allBcDefinedPartNames_;

    void defineType(const std::string name, const EnumDomainPartType type);
    bool isExpectedType(const std::string name, const EnumDomainPartType type);

    void addUniqueBcNameToList(const std::string name, 
                                std::vector<std::string>& vect);
};

}
#endif // SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_PARTSTYPEINFO_H