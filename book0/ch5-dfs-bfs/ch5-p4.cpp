#include <iostream>
#include <queue>
#include <utility>

int main() {
    int n, m {};
    std::cin >> n >> m;
    std::cin >> std::ws;

    char map_str[n * (m + 1) + 1] {};
    std::cin.getline(map_str, n * (m + 1), '#');

    int map[n][m] {};
    for (auto row {0}, idx {0}; row != n; ++row) {
        for (auto col {0}; col != m; ++col) {
            map[row][col] = static_cast<int>(map_str[idx] - '0');
            ++idx;
        }
        ++idx;
    }

    std::queue<std::pair<int, int>> q {};
    q.emplace(std::pair<int, int> {0, 0});
    while (!q.empty()) {
        std::pair<int, int> cur {q.front()};
        q.pop();

        if (cur.first == n - 1 && cur.second == m - 1) break;

        auto cnt {0};
        if (cur.first - 1 > 0 && map[cur.first - 1][cur.second] == 1) {
            q.emplace(std::pair<int, int> {cur.first - 1, cur.second});
            map[cur.first - 1][cur.second] = map[cur.first][cur.second] + 1;
        }
        if (cur.second - 1 > 0 && map[cur.first][cur.second - 1] == 1) {
            q.emplace(std::pair<int, int> {cur.first, cur.second - 1});
            map[cur.first][cur.second - 1] = map[cur.first][cur.second] + 1;
        }
        if (cur.first + 1 < n && map[cur.first + 1][cur.second] == 1) {
            q.emplace(std::pair<int, int> {cur.first + 1, cur.second});
            map[cur.first + 1][cur.second] = map[cur.first][cur.second] + 1;
        }
        if (cur.second + 1 < m && map[cur.first][cur.second + 1] == 1) {
            q.emplace(std::pair<int, int> {cur.first, cur.second + 1});
            map[cur.first][cur.second + 1] = map[cur.first][cur.second] + 1;
        }
    }

    std::cout << std::endl;
    for (int row {0}; row != n; ++row) {
        for (int col {0}; col != m; ++col) {
            std::cout << map[row][col];
        }
        std::cout << std::endl;
    }
    std::cout << map[n-1][m-1] << std::endl;

    return 0;
}