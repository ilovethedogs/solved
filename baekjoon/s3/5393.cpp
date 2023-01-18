#include <iostream>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto t {int{}};
    std::cin >> t;
    for (auto i {0}; i != t; ++i) {
        auto n {int{}};
        std::cin >> n;

        if (n == 1) {
            std::cout << "2\n";
            continue;
        }

        auto result {n - (n >> 1)};
        auto start {int{}};
        for (auto odd {std::clamp((n - 1) / 3, 1, n - 1)}; odd <= n; ++odd) {
            if (odd * 3 + 1 > n && (odd & 0b1))  {
                start = odd;
                break;
            }
        }
        result += ((n - start + 1) / 2) + (n & 0b1);
        std::cout << result << '\n';
    }

    return EXIT_SUCCESS;
}