#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int get_sum(std::vector<int>& v) {
    auto result {0};
    for (auto i {0}; i != v.size() - 1; ++i)
        result += abs(v[i] - v[i + 1]);
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    std::cin >> N;

    auto v {std::vector<int> (N, 0)};
    for (auto i {0}; i != N; ++i)
        std::cin >> v[i];

    std::sort(v.begin(), v.end());

    auto result {0};
    do {
        result = std::max(result, get_sum(v));
    } while (std::next_permutation(v.begin(), v.end()));

    std::cout << result;

    return EXIT_SUCCESS;
}
