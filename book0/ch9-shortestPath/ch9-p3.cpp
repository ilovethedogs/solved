#include <iostream>
#include <queue>
#include <functional>

constexpr auto INF {1'000'000'000};

int main() {
    auto n {int{}};
    auto m {int{}};
    auto c {int{}};
    std::cin >> n >> m >> c >> std::ws;

    int g[n + 1][n + 1];
    for (auto i {0}; i != n + 1; ++i)
        for (auto j {0}; j != n + 1; ++j)
            g[i][j] = INF;

    for (auto i {1}; i != n + 1; ++i)
        g[i][i] = 0;

    auto x {int{}};
    auto y {int{}};
    auto z {int{}};
    for (auto i {0}; i != m; ++i) {
        std::cin >> x >> y >> z; 
        g[x][y] = z;
    }

/*
    for (auto i {1}; i != n + 1; ++i) {
        for (auto j {1}; j != n + 1; ++j) {
            std::cout << g[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */

    auto pq {std::priority_queue<int, std::vector<int>, std::greater<int>};

    return 0;
}