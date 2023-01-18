#include <bits/stdc++.h>

int main() {
    auto N {int{}};
    auto K {int{}};
    std::cin >> N >> K;

    auto v {std::vector<std::vector<int>> (2, std::vector<int> (7, 0))};
    auto gender {0};
    auto room {0};
    for (auto i {0}; i != N; ++i) {
        std::cin >> gender >> room;
        ++v[gender][room];
    }

    auto result {0};
    for (auto i {0}; i != 2; ++i) {
        for (auto j {1}; j != 7; ++j) {
            result += static_cast<int>(std::ceil(static_cast<double>(v[i][j]) / K));
        }
    }
    std::cout << result;

    return EXIT_SUCCESS;
}