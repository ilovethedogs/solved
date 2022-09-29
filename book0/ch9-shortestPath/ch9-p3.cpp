#include <iostream>
#include <map>
#include <vector>

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

    auto v {std::vector<int> (n + 1, INF)};
    auto done {std::vector<bool> {false}};
    auto mm {std::multimap<int, int> {}};
    mm.insert({0, c});
    while (!mm.empty()) {
        auto cur {*std::begin(mm)};
        mm.erase(std::begin(mm));  
        if (done[cur.second]) continue;
        done[cur.second] = true;

        for (auto row {cur.second}, col {1}; col != n + 1; ++col) {
            if (g[row][col] != 0 && v[col] > g[row][col] + cur.first) {
                v[col] = g[row][col] + cur.first;
                mm.insert({v[col], col});
            }
        }
    }

    auto num_of_city {0};
    auto time {0};
    for (auto i : v)  {
        num_of_city += (i != 0 && i != INF);
        if (i != INF) time = std::max(time, i);
    }

    std::cout << num_of_city << " " << time << std::endl;

    return 0;
}