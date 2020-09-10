#include "Cache.h"

namespace utec {

    namespace memory {

        template<class K, class V>
        Cache<K, V>::Cache(int maxSize, K (*cachePolicy)(Cache<K, V> *),
                           void (*update)(Cache<K, V> *, K, V)):
                maxSize(maxSize),
                cachePolicy(cachePolicy),
                update(update) {}

        template<class K, class V>
        void Cache<K, V>::insertKeyValuePair(K key, V value) {
            if (positions.find(key) != positions.end()) {
                (*positions[key]).second = value;
            } else {
                if (values.size() == maxSize) {
                    positions.erase(cachePolicy(this));
                }
                values.push_front({key, value});
                positions[key] = values.begin();
            }
        }

        template<typename K, typename V>
        optional<V> Cache<K, V>::getValueFromKey(K key) {
            if (positions.find(key) != positions.end()) {
                V value = (*positions[key]).second;
                if (update) {
                    update(this, key, value);
                }
                return value;
            } else {
                return nullopt;
            }
        }

        template<typename K, typename V>
        optional<K> Cache<K, V>::getMostRecentKey() {
            if (values.empty()) return nullopt;
            return values.front().first;
        }

    }

}