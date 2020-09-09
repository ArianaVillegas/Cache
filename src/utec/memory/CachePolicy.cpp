#include "Cache.h"
#include "Cache.cpp"

// Delete Policy

template<class K, class V>
K First(Cache<K, V>* cache){
    auto values = cache->getValues();
    K key_delete = values->front().first;
    values->pop_front();
    return key_delete;
}

template<class K, class V>
K Last(Cache<K, V>* cache){
    auto values = cache->getValues();
    K key_delete = values->back().first;
    values->pop_back();
    return key_delete;
}

//Update Policy

template<class K, class V>
void LRU(Cache<K, V>* cache, K key, V value){
    auto values = cache->getValues();
    auto positions = cache->getPositions();
    values->erase((*positions)[key]);
    values->push_front({key,value});
    (*positions)[key] = values->begin();
}