#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto a {int{}};
    auto b {int{}};
    auto c {int{}};
    std::cin >> a >> b >> c;

    uint64_t result {a * b * c};
    auto v {std::array<int, 10> {}};
    while (result) {
        ++v[result % 10];
        result /= 10;
    }
    for (auto i : v) {
        std::cout << i << '\n';
    } 

    return EXIT_SUCCESS;
}