#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto T {int{}} ;
    std::cin >> T;

    for (auto t {0}; t != T; ++t) {
        auto N {int{}};
        std::cin >> N;

        auto v {std::vector<int> (N + 1, 0)};
        for (auto i {1}; i != N + 1; ++i)
            std::cin >> v[i];

        auto target {int{}};
        std::cin >> target;

        auto mem {std::vector<std::vector<int>> (N + 1, std::vector<int> (target + 1, 0))};
        for (auto i {1}; i != N + 1; ++i)
            for (auto j {1}; j != target + 1; ++j) {
                mem[i][j] = mem[i - 1][j];
                if (j - v[i] >= 0) mem[i][j] += mem[i][j - v[i]] + (mem[i][j - v[i]] == 0 && (j - v[i]) % v[i] == 0);
            }

        std::cout << mem[N][target] << '\n';
    }

    return EXIT_SUCCESS;
}
