#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);

    auto N{int{}};
    std::cin >> N;

    auto v{std::vector<int>(N, 0)};
    for (auto i{0}; i != N; ++i)
        std::cin >> v[i];

    auto X {2'000'001};
    auto mat {std::vector<std::vector<int>> (N, std::vector<int> (N, 0))};
    for (auto pivot {0}; pivot != N; ++pivot) {
        mat[pivot][pivot] = X;
        for (auto i {pivot + 1}; i < N; ++i) {
            auto diff {v[i] - v[pivot]};
            auto mod {(diff % (i - pivot)) == 0};
            mat[pivot][i] = X * !mod + (diff / (i - pivot)) * mod;
            mat[i][pivot] = mat[pivot][i];
        }
    }

    auto result {1'000};
    for (auto i {0}; i != N; ++i) {
        auto cur {0};
        auto um {std::unordered_map<int, int> {}};
        for (auto j {0}; j != N; ++j) {
            if (mat[i][j] != X)
                cur = std::max(cur, ++um[mat[i][j]]);
        }
        result = std::min(result, N - 1 - cur);
    }

    std::cout << result;

    return EXIT_SUCCESS;
}
