#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto v {std::vector<int> (9, 0)};
    auto sum {0};
    for (auto i {0}; i != 9; ++i) {
        std::cin >> v[i];
        sum += v[i];
    }

    auto result {std::vector<int> {}};
    result.reserve(7);
    for (auto i {0}; i != 8; ++i)
        for (auto j {i + 1}; j != 9; ++j)
            if (sum - v[i] - v[j] == 100) {
                for (auto k {0}; k != 9; ++k)
                    if (k != i && k != j) result.push_back(v[k]);
                goto end;
            }

    end:
    std::sort(result.begin(), result.end());
    for (auto i : result) std::cout << i << '\n';

    return EXIT_SUCCESS;
}