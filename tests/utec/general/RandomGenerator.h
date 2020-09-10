#pragma once

#ifndef LRU_CACHE_RANDOMGENERATOR_H
#define LRU_CACHE_RANDOMGENERATOR_H

#include <random>
#include <type_traits>
#include <fstream>

#define MIN 1
#define MAX 1000

using namespace std;

namespace utec {

    namespace tests {

        namespace tools {

            class RandomGenarator {
            private:
                mt19937 rng;

            public:
                RandomGenarator();

                int generateRandom(int min = MIN, int max = MAX);

                void generateRandomInstructions(unsigned int size);
            };

        }

    }

}

#endif
