#ifndef SIMPLEFVM_DATASTORES_ADT_MAPADT_H
#define SIMPLEFVM_DATASTORES_ADT_MAPADT_H

#include <cstddef>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

namespace datastores {

template <class T>
class MapAdt {
public:
    MapAdt();
    ~MapAdt();

    void addObject(std::string name, const T& object);
    void addObjectPtr(std::string name, T pObject);
    void addObjectUPtr(std::string name, T pObject);
    T& getObject(std::string name);
    size_t getSize();
    bool isMapKey(std::string name);
    void clearMap();

private:
    std::map<std::string, T> map_;
    size_t size_ = 0;
};


template <class T>
MapAdt<T>::MapAdt() {

}

template <class T>
MapAdt<T>::~MapAdt() {

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
void MapAdt<T>::addObjectUPtr(std::string name, T pObject) {
    map_.insert(std::make_pair(name, std::move(pObject)));
}


template <class T>
T& MapAdt<T>::getObject(std::string name) {
    return map_[name];
}


template <class T>
size_t MapAdt<T>::getSize() {
    return map_.size();
}


template <class T>
bool MapAdt<T>::isMapKey(std::string name) {
    ///TODO: watch later.
    if (map_.count(name) > 0) {
        return true;
    }
    else {
        return false;
    }
}


template <class T>
void MapAdt<T>::clearMap() {
    map_.clear();
}

}
#endif // SIMPLEFVM_DATASTORES_ADT_MAPADT_H