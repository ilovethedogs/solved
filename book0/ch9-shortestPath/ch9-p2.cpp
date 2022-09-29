#include <iostream>

constexpr auto INF{int{1'000'000'000}};

int main()
{
    auto n{int{}};
    auto m{int{}};
    std::cin >> n >> m >> std::ws;

    int g[n + 1][n + 1]{0};
    for (auto i{0}; i != n + 1; ++i)
        for (auto j{0}; j != n + 1; ++j)
            g[i][j] = INF;

    for (auto i{1}; i != n + 1; ++i)
        g[i][i] = 0;

    auto r{int{}};
    auto c{int{}};
    for (auto i{0}; i != m; ++i)
    {
        std::cin >> r >> c;
        g[r][c] = g[c][r] = 1;
    }

    auto x {int{}};
    auto k {int{}};

    std::cin >> x >> k;

    // floyd-warshall
    for (auto i {1}; i != n + 1; ++i) {
        for (auto r {1}; r != n + 1; ++r) {
            for (auto c {r + 1}; c != n + 1; ++c) {
                g[r][c] = g[c][r] = std::min(g[r][c], g[r][i] + g[i][c]);
            }
        }
    }
     
    std::cout << ((g[1][k] + g[k][x]) * (g[1][k] + g[k][x] < 1'000'000'000) + -1 * (g[1][k] + g[k][x] >= 1'000'000'000)) << std::endl;

    return 0;
}