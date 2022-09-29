#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    auto M {int{}};
    std::cin >> N >> M;

    auto v {std::vector<std::vector<char>> (N, std::vector<char> (M, 0))};
    for (auto i {0}; i != N; ++i)
        for (auto j {0}; j != M; ++j)
            std::cin >> v[i][j];

    auto result {std::numeric_limits<int>::max()};
    auto b_pivot {char{'B'}};
    auto w_pivot {char{'W'}};
    for (auto i {0}; i != N - 8 + 1; ++i) {
        for (auto j {0}; j != M - 8 + 1; ++j) {
            auto b_temp {0};
            auto w_temp {0};

            for (auto r {i}; r != i + 8; ++r) {
                b_pivot = 'W' * (r & 0x1) + 'B' * !(r & 0x1);
                w_pivot = 'B' * (r & 0x1) + 'W' * !(r & 0x1);

                b_temp += b_pivot != v[r][j];
                w_temp += w_pivot != v[r][j];

                b_pivot = 'W' * (b_pivot == 'B') + 'B' * (b_pivot == 'W');
                w_pivot = 'W' * (w_pivot == 'B') + 'B' * (w_pivot == 'W');
                for (auto c {j + 1}; c != j + 8; ++c) {
                    b_temp += b_pivot != v[r][c];
                    w_temp += w_pivot != v[r][c];

                    b_pivot = 'W' * (b_pivot == 'B') + 'B' * (b_pivot == 'W');
                    w_pivot = 'W' * (w_pivot == 'B') + 'B' * (w_pivot == 'W');
                }
            }

            result = std::min(result, b_temp);
            result = std::min(result, w_temp);
        }
    }

    std::cout << result;

    return EXIT_SUCCESS;
}

