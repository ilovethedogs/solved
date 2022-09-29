#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    std::cin >> N;
    auto K {int{}};
    std::cin >> K;

    auto v {std::vector<std::vector<int>> (N + 1, std::vector<int> (2, 0))};
    for (auto i {1}; i != N + 1; ++i)
        std::cin >> v[i][0] >> v[i][1];

    std::sort(v.begin(), v.end(), [] (auto const& a, auto const& b) {
        return a[0] < b[0];
    });

    auto mem {std::vector<std::vector<unsigned int>> (N + 1, std::vector<unsigned int> (K + 1, 0))};
    for (auto r {1}; r != N + 1; ++r) {
        for (auto c {1}; c != K + 1; ++c) {
            if (c - v[r][0] >= 0) mem[r][c] = std::max(mem[r - 1][c], mem[r - 1][c - v[r][0]] + v[r][1]);
            else mem[r][c] = mem[r - 1][c];
        }
    }

    std::cout << mem[N][K];

    return EXIT_SUCCESS;
}

