#pragma once

#ifndef LRU_CACHE_CACHEPOLICY_H
#define LRU_CACHE_CACHEPOLICY_H

namespace utec {

    namespace memory {

        namespace policy {

            #include "Cache.h"
            #include "Cache.cpp"

            using namespace utec::memory;

            template<class K, class V>
            K First(Cache<K, V> *cache);

            template<class K, class V>
            K Last(Cache<K, V> *cache);

            template<class K, class V>
            void LRU(Cache<K, V> *cache, K key, V value);

        }

    }

}

#endif
