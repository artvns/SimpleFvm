#include "PartsTypeInfo.h"

namespace fvmsolver {

PartsTypeInfo::PartsTypeInfo() {

}


std::vector<std::string>& PartsTypeInfo::getAllBcDefinedPartNames() {
    return allBcDefinedPartNames_;
}


std::string PartsTypeInfo::getDefinedPartName(size_t index) {
    return allBcDefinedPartNames_.at(index);
}


size_t PartsTypeInfo::getDefinedPartNamesAmount() {
    return allBcDefinedPartNames_.size();
}


void PartsTypeInfo::defineTypeAsInterior(const std::string name) {
    defineType(name, PART_TYPE_INTERIOR);
    addUniqueBcNameToList(name, allBcDefinedPartNames_);
}

void PartsTypeInfo::defineTypeAsVelocityInlet(const std::string name) {
    defineType(name, PART_TYPE_VELOCITY_INLET);
    addUniqueBcNameToList(name, allBcDefinedPartNames_);
}

void PartsTypeInfo::defineTypeAsPressureInlet(const std::string name) {
    defineType(name, PART_TYPE_PRESSURE_INLET);
    addUniqueBcNameToList(name, allBcDefinedPartNames_);
}

void PartsTypeInfo::defineTypeAsPressureOutlet(const std::string name) {
    defineType(name, PART_TYPE_PRESSURE_OUTLET);
    addUniqueBcNameToList(name, allBcDefinedPartNames_);
}

void PartsTypeInfo::defineTypeAsMovingWall(const std::string name) {
    defineType(name, PART_TYPE_MOVING_WALL);
    addUniqueBcNameToList(name, allBcDefinedPartNames_);
}

void PartsTypeInfo::defineTypeAsStaticWall(const std::string name) {
    defineType(name, PART_TYPE_STATIC_WALL);
    addUniqueBcNameToList(name, allBcDefinedPartNames_);
}



bool PartsTypeInfo::isInterior(const std::string name) {
    return isExpectedType(name, PART_TYPE_INTERIOR);
}

bool PartsTypeInfo::isVelocityInlet(const std::string name) {
    return isExpectedType(name, PART_TYPE_VELOCITY_INLET);
}

bool PartsTypeInfo::isPressureInlet(const std::string name) {
    return isExpectedType(name, PART_TYPE_PRESSURE_INLET);
}

bool PartsTypeInfo::isPressureOutlet(const std::string name) {
    return isExpectedType(name, PART_TYPE_PRESSURE_OUTLET);
}

bool PartsTypeInfo::isMovingWall(const std::string name) {
    return isExpectedType(name, PART_TYPE_MOVING_WALL);
}

bool PartsTypeInfo::isStaticWall(const std::string name) {
    return isExpectedType(name, PART_TYPE_STATIC_WALL);
}



void PartsTypeInfo::defineType(const std::string name, 
                                        const EnumDomainPartType type) {
    if (!partTypeMap_.isMapKey(name)) {
        partTypeMap_.addObject(name, type);
    }
    else {
        partTypeMap_.getObject(name) = type;
    }
}

bool PartsTypeInfo::isExpectedType(const std::string name, 
                                        const EnumDomainPartType type) {

    if (type == partTypeMap_.getObject(name)) {
        return true;
    }
    else {
        return false;
    }
}

void PartsTypeInfo::addUniqueBcNameToList(const std::string name, 
                                    std::vector<std::string>& vect) {

    if(std::find(vect.begin(), vect.end(), name) == vect.end()) {
        vect.push_back(name);
    }
}

}