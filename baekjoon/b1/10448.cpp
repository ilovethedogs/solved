#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    std::cin >> N;

    auto v {std::vector<int> (N, 0)};
    for (auto i {0}; i != N; ++i)
        std::cin >> v[i];

    for (auto i : v) {
        for (auto a {1}; a != 45; ++a) {
            for (auto b {1}; b != 45; ++b) {
                for (auto c {1}; c != 45; ++c) {
                    if (a * a + b * b + c * c + a + b + c == 2 * i) {
                        std::cout << 1 << '\n';
                        goto cont;
                    }
                }
            }
        }

        std::cout << 0 << '\n';
        cont:
            ;
    }

    return EXIT_SUCCESS;
}