#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    std::cin >> N;

    auto first {std::string{}};
    auto second {std::string{}};
    for (auto i {0}; i != N; ++i) {
        std::cin >> first >> second;
        auto v0 {std::vector<int> ('z' - 'a' + 1, 0)};
        auto v1 {std::vector<int> ('z' - 'a' + 1, 0)};
        std::for_each(std::begin(first), std::end(first), [&v0](auto ch) {
            ++v0[static_cast<size_t>(ch - 'a')];
        });
        std::for_each(std::begin(second), std::end(second), [&v1](auto ch) {
            ++v1[static_cast<size_t>(ch - 'a')];
        });
        std::cout  << (v0 == v1 ? "Possible\n" : "Impossible\n");
    }

    return EXIT_SUCCESS;
}
