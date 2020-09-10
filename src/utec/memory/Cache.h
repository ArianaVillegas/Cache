#pragma once

#ifndef LRU_CACHE_CACHE_H
#define LRU_CACHE_CACHE_H

#include <unordered_map>
#include <list>
#include <optional>

using namespace std;

namespace utec {

    namespace memory {

        template<class K, class V>
        class Cache {
        private:

            int maxSize;

            unordered_map<K, typename list<pair<K, V>>::iterator> positions;
            list<pair<K, V>> values;

            K (*cachePolicy)(Cache<K, V> *);

            void (*update)(Cache<K, V> *, K, V);

        public:

            Cache(int maxSize, K (*cachePolicy)(Cache<K, V> *),
                  void (*update)(Cache<K, V> *, K, V));

            void insertKeyValuePair(K key, V value);

            optional<V> getValueFromKey(K key);

            optional<K> getMostRecentKey();

            int getMaxSize() { return maxSize; }

            auto getPositions() { return &positions; }

            auto getValues() { return &values; }

        };

    }

}

#endif