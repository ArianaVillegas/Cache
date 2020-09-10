#include "tests/utec/general/RandomGenerator.h"
#include "tests/utec/memory/Cache_test.h"
#include "tests/utec/memory/Cache_test.cpp"

using namespace utec::memory::policy;
using namespace utec::tests::tools;

int main() {

    RandomGenarator r;
    r.generateRandomInstructions(100000);

    Tester<char, int> t;
    double time;

    cout << "--------------------------LRU--------------------------\n";
    time = t.execute(0, 10, Last, LRU);
    cout << "Execution time: " << time << '\n';
    cout << "--------------------------LRU--------------------------\n\n\n";

    cout << "--------------------------FIFO--------------------------\n";
    time = t.execute(0, 10, Last, NULL);
    cout << "Execution time: " << time << '\n';
    cout << "--------------------------FIFO--------------------------\n\n\n";

    cout << "--------------------------LIFO--------------------------\n";
    time = t.execute(0, 10, First, NULL);
    cout << "Execution time: " << time << '\n';
    cout << "--------------------------LIFO--------------------------\n\n\n";

    return 0;
}
