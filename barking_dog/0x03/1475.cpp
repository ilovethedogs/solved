#include <bits/stdc++.h>

int main() {
    auto num {int{}};
    std::cin >> num;

    auto arr {std::array<int, 10> {}};
    while (num) {
        auto i {num % 10};
        if (i == 6 || i == 9)
            ++arr[6];
        else
            ++arr[i];
        num /= 10;
    }

    auto result {std::max(1, static_cast<int>(std::ceil(arr[6] / 2.0f)))};
    for (auto i {0}; i != 6; ++i)
        result = std::max(result, arr[i]);
    for (auto i {7}; i != 10; ++i)
        result = std::max(result, arr[i]);
    std::cout << result; 

    return EXIT_SUCCESS;
}