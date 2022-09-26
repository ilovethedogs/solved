#include <iostream>

int main() {
    auto N {int{}};
    std::cin >> N;

    for (auto a {0}; a != 10; ++a) {
        for (auto b {0}; b != 10; ++b) {
            for (auto c {0}; c != 10; ++c) {
                for (auto d {0}; d != 10; ++d) {
                    for (auto e {0}; e != 10; ++e) {
                        for (auto f {0}; f != 10; ++f) {
                            auto result = (f + 10 * e + 100 * d + 1'000 * c + 10'000 * b + 100'000 * a);
                            if (a + b + c + d + e + f + result == N)  {
                                std::cout << result;
                                return EXIT_SUCCESS;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << 0;
    return EXIT_SUCCESS;
}
