#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    auto S {int{}};
    std::cin >> N >> S;

    auto v {std::vector<int> (N, 0)};
    for (auto i {0}; i != N; ++i)
        std::cin >> v[i];

    auto result {0};
    auto s {std::vector<int> (N, 0)};
    auto limit {1 << N};
    for (auto selector {0b1}; selector < limit; ++selector) {
        for (auto i {0}, j {selector}; i != N && j; ++i, j >>= 1)
            s[i] = j & 0b1;
        auto temp {0};
        for (auto i {0}; i != N; ++i)
            temp += v[i] * s[i];
        result += temp == S;
        for (auto i {0}; i != N; ++i) s[i] = 0;
    }

    std::cout << result;

    return EXIT_SUCCESS;
}
