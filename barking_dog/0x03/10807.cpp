#include <bits/stdc++.h>

int main() {
    auto N {int{}};
    std::cin >> N;
    auto v {std::vector<int> (N, 0)};
    for (auto i {0}; i != N; ++i)
        std::cin >> v[i];
    auto V {int{}};
    std::cin >> V;

    auto result {0};
    std::for_each(std::begin(v), std::end(v), [&result, V](auto i) {
        result += V == i;
    });
    std::cout << result;
    
    return EXIT_SUCCESS;
}