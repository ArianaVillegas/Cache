#include <iostream>
#include "RandomGenerator.h"

namespace utec {

    namespace tests {

        namespace tools {

            RandomGenarator::RandomGenarator() {
                rng.seed(random_device()());
            }

            int RandomGenarator::generateRandom(int min, int max) {
                uniform_int_distribution<mt19937::result_type> distribution(min, max);
                return distribution(rng);
            }

            void RandomGenarator::generateRandomInstructions(unsigned int size) {
                ofstream outfile;
                remove("instructions.txt");
                outfile.open("instructions.txt", ios::out | ios::app);
                for (int i = 0; i < size; i++) {
                    int opt = generateRandom(0, 2);
                    outfile << opt;
                    if (opt) {
                        outfile << ' ' << generateRandom(65, 90);
                        if (opt == 2)
                            outfile << ' ' << generateRandom(1, 10);
                    }
                    outfile << endl;
                }
                outfile.close();
            }

        }

    }

}