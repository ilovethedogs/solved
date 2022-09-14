#include <iostream>
#include <vector>

int main() {
    auto N {int{}};
    std::cin >> N;
    auto odd {std::vector<int> {}};
    auto temp {size_t {}};
    for (auto i {0}; i != N; ++i) {
        std::cin >> temp;
        if (temp & 0x1) odd.push_back(i);
    }

    auto result1 {size_t{}};
    auto result2 {size_t{}};
    for (auto i {0}; i != odd.size(); ++i) {
        result1 += (odd[i] - i);
        result2 += (N - 1 - i) - odd[odd.size() - 1 - i];
    }
    std::cout << std::min(result1, result2);

    return EXIT_SUCCESS;
}
