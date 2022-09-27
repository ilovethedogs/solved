#include <iostream>
#include <vector>

std::pair<int, int> determinator(std::vector<int>& a, std::vector<int>& b) {
    auto result {std::pair<int, int> {0, 0}};

    bool ball_suspect[3] {true, true, true};

    // check for strikes
    if (a[0] == b[0]) {
        ++result.first;
        ball_suspect[0] = false;
    }
    if (a[1] == b[1]) {
        ++result.first;
        ball_suspect[1] = false;
    }
    if (a[2] == b[2]) {
        ++result.first;
        ball_suspect[2] = false;
    }

    // check for balls
    for (auto i {0}; i != 3; ++i)
        if (ball_suspect[i])
            for (auto j {0}; j != 3; ++j)
                result.second += a[j] == b[i];

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    std::cin >> N;

    auto input {std::vector<std::vector<int>> {}};
    input.reserve(N);
    auto temp1 {int{}};
    auto temp2 {int{}};
    auto temp3 {int{}};
    for (auto i {0}; i != N; ++i) {
        std::cin >> temp1 >> temp2 >> temp3;
        input.push_back({temp1, temp2, temp3});
    }

    auto v {std::vector<std::vector<int>> {}};
    v.reserve(9 * 8 * 7);
    for (auto i {1}; i != 10; ++i) {
        for (auto j {1}; j != 10; ++j) {
            if (i == j) continue;
            for (auto k {1}; k != 10; ++k) {
                if (k == i || k == j) continue;
                v.push_back({i, j, k});
            }
        }
    }

    for (auto& vv : input) {
        auto target {std::vector<int> {vv[0] / 100, (vv[0] / 10) % 10, vv[0] % 10}};
        for (auto it {v.begin()}; it != v.end(); ++it) {
            auto r {determinator(target, *it)};
            if (r.first != vv[1] || r.second != vv[2]) {
                auto temp {&it};
                std::iter_swap(it, v.end() - 1);
                v.pop_back();
                it = *temp;
                --it;
            }
        }
    }


    std::cout << v.size();

    return EXIT_SUCCESS;
}