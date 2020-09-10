#include <iostream>
#include <optional>

using namespace std;

namespace utec {

    namespace tests {

        namespace tools {

            const string none = "None";

            template<typename T>
            void print(optional<T> text) {
                if (text.has_value()) {
                    cout << text.value() << '\n';
                } else {
                    cout << none << '\n';
                }
            }
        }

    }

}