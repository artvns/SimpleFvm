#include "AbstractNumsPacker.h"

namespace meshloader {

AbstractNumsPacker::AbstractNumsPacker(
                                DataStoreMasks& dataStoreMasks, 
                                Mesh& mesh, 
                                NumsSets& numsSets) :
                                            dataStoreMasks_(dataStoreMasks),
                                            mesh_(mesh),
                                            numsSets_(numsSets) {

}

AbstractNumsPacker::~AbstractNumsPacker() {

}

void AbstractNumsPacker::packAll() {
    size_t partsAmount = numsSets_.getPartNamesSet().size();

    for (size_t part = 0; part < partsAmount; part++) {
        char   partName = numsSets_.getPartNamesSet().at(part);
        size_t partSize = numsSets_.getNumsSet(partName).size();

        std::string name(1, partName);

        createStores(name, partSize);
        packPart(name, partSize);
    }
}

}