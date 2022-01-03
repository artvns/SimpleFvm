#include "AbstractNumsSetsCreator.h"

namespace meshloader {

AbstractNumsSetsCreator::AbstractNumsSetsCreator( 
                                Mesh& mesh, 
                                NumsSets& numsSetsP,
                                NumsSets& numsSetsVel) :
                                            mesh_(mesh), 
                                            numsSetsP_(numsSetsP),
                                            numsSetsVel_(numsSetsVel) {

}

AbstractNumsSetsCreator::~AbstractNumsSetsCreator() {

}

void AbstractNumsSetsCreator::createNamedSets() {

    for (size_t numSet = 0; numSet < numsSetsP_.getSetsAmount(); numSet++) {
        
        char name = numsSetsP_.getPartNamesSet().at(numSet);
        if ('z' == name) {
            createInteriorSet(name);
        }
        else {
            createFacesSets(name);
        }
    }
}

bool AbstractNumsSetsCreator::isGhostCellW(size_t globNum) {
    return mesh_.getCell(globNum)->getMacroCellW()->isGhostCell();
}

bool AbstractNumsSetsCreator::isGhostCellE(size_t globNum) {
    return mesh_.getCell(globNum)->getMacroCellE()->isGhostCell();
}

bool AbstractNumsSetsCreator::isGhostCellN(size_t globNum) {
    return mesh_.getCell(globNum)->getMacroCellN()->isGhostCell();
}

bool AbstractNumsSetsCreator::isGhostCellS(size_t globNum) {
    return mesh_.getCell(globNum)->getMacroCellS()->isGhostCell();
}

}