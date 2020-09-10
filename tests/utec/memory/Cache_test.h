#pragma once

#ifndef CACHE_TEST_H
#define CACHE_TEST_H

#include <stdexcept>
#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

#include "../../../src/utec/memory/CachePolicy.cpp"

using namespace utec::memory;

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

template<class K, class V>
class Tester {

public:
    double execute(bool p, int maxSize, K (*cachePolicy)(Cache<K,V>*), void (*update)(Cache<K,V>*, K, V));
};

#endif