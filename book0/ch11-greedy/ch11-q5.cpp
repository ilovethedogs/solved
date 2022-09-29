#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

int main() {
    auto n {int{}};
    auto m {int{}};
    std::cin >> n >> m >> std::ws;

    auto temp {int{}};
    auto v {std::vector<int> (11, 0)};
    for (auto i {0}; i != n; ++i) {
        std::cin >> temp;
        ++v[temp];
    }
    
    auto result {0};
    for (auto i {1}; i != v.size(); ++i) {
        auto start {v.begin() + 1 + i};
        result += v[i] * std::accumulate(start, v.end(), 0, std::plus<>());
    }

    std::cout << result << std::endl;
    return 0;
}