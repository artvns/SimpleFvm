#ifndef SIMPLEFVM_FVMSOLVER_TOOLS_LOCALADT_FVMSOLVERMAPADT_H
#define SIMPLEFVM_FVMSOLVER_TOOLS_LOCALADT_FVMSOLVERMAPADT_H

#include <cstddef>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <memory>


namespace fvmsolver {

template <class T>
class MapAdt {
public:
    MapAdt();

    void addObject(std::string name, const T& object);
    void addObjectPtr(std::string name, T pObject);
    void addObjectUniquePtr(std::string name, T pObject);
    T& getObject(std::string name);
    size_t getSize();
    bool isMapKey(std::string name);

private:
    size_t size_ = 0;
    std::map<std::string, T> map_;
};

template <class T>
MapAdt<T>::MapAdt() {

}

template <class T>
void MapAdt<T>::addObject(std::string name, const T& object) {
    map_.insert(std::make_pair(name, object));
}

template <class T>
void MapAdt<T>::addObjectPtr(std::string name, T pObject) {
    map_.insert(std::make_pair(name, pObject));
}

template <class T>
void MapAdt<T>::addObjectUniquePtr(std::string name, T pObject) {
    map_.insert(std::make_pair(name, std::move(pObject)));
}

template <class T>
T& MapAdt<T>::getObject(std::string name) {
    return map_.at(name);
}

template <class T>
size_t MapAdt<T>::getSize() {
    return map_.size();
}

template <class T>
bool MapAdt<T>::isMapKey(std::string name) {
    if (map_.count(name) > 0) {
        return true;
    }
    else {
        return false;
    }
}

}
#endif // SIMPLEFVM_FVMSOLVER_TOOLS_LOCALADT_FVMSOLVERMAPADT_H