#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto n {int{}};
    std::cin >> n;

    auto result {1};
    while (n != 1) {
        ++result;
        if (n & 0b1) {
            n *= 3;
            ++n;
        }
        else {
            n >>= 1;
        }
    }
    std::cout << result;

    return EXIT_SUCCESS;
}