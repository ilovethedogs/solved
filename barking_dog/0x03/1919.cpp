#include <bits/stdc++.h>

int main() {
    auto first {std::string{}};
    auto second {std::string{}};
    std::cin >> first >> second;

    auto v0 {std::vector<int> ('z' - 'a' + 1, 0)};
    auto v1 {std::vector<int> ('z' - 'a' + 1, 0)};
    std::for_each(std::begin(first), std::end(first), [&v0](auto ch) {
        ++v0[ch - 'a'];
    });
    std::for_each(std::begin(second), std::end(second), [&v1](auto ch) {
        ++v1[ch - 'a'];
    });

    auto result {0};
    for (auto i {0}; i != 'z' - 'a' + 1; ++i)
        result += std::abs(v0[i] - v1[i]) * (v0[i] != v1[i]);
    std::cout << result;

    return EXIT_SUCCESS;
}