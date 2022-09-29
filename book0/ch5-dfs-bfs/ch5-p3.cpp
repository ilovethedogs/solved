#include <iostream>
#include <stack>
#include <string>
#include <utility>

int main() {
    int n, m {};
    std::cin >> n >> m;

    std::cin >> std::ws;
    char ice_str[n * (m + 1) + 1];
    std::cin.getline(ice_str, n * (m + 1), '#');

    int ice[n][m] {};
    for (auto row {0}, idx {0}; row != n; ++row) {
        for (auto col {0}; col != m; ++col) {
            ice[row][col] = static_cast<int>(ice_str[idx] - '0');
            ++idx;
        }
        ++idx;
    }

    std::stack<std::pair<int, int>> s {};
    int result {0};
    for (auto row {0}; row != n; ++row) {
        for (auto col {0}; col != m; ++col) {
            if (ice[row][col] == 0) {
                ++result;

                s.emplace(std::pair<int, int> {row, col});
                while (!s.empty()) {
                    std::pair<int, int> cur {s.top()};
                    s.pop();
                    ice[cur.first][cur.second] = 2;

                    if (cur.first - 1 > 0 && ice[cur.first - 1][cur.second] == 0)
                        s.emplace(std::pair<int, int> {cur.first - 1, cur.second});
                    if (cur.second + 1 < m && ice[cur.first][cur.second + 1] == 0)
                        s.emplace(std::pair<int, int> {cur.first, cur.second + 1});
                    if (cur.first + 1 < n && ice[cur.first + 1][cur.second] == 0)
                        s.emplace(std::pair<int, int> {cur.first + 1, cur.second});
                    if (cur.second - 1 > 0 && ice[cur.first][cur.second - 1] == 0)
                        s.emplace(std::pair<int, int> {cur.first, cur.second - 1});
                }
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}