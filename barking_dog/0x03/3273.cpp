#include <bits/stdc++.h>

int main() {
    auto n {int{}};
    std::cin >> n;
    auto nums {std::vector<int> (n, 0)};
    for (auto i {0}; i != n; ++i)
        std::cin >> nums[i];
    auto x {int{}};
    std::cin >> x;

    // 0 is not included
    auto arr {std::array<int, 1'000'001> {}};
    auto result {0};
    for (auto i : nums) {
        if ((x - i <= 1'000'000) & (x - i >= 1)) {
            if (arr[x - i]) ++result;
            else ++arr[i];
        }
    }
    std::cout << result;

    return EXIT_SUCCESS;
}