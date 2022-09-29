#include <iostream>

int main() {
    int n = 25, k = 5;
    //std::cin >> n >> k;

    auto result {0};
    while (n != 1) {
        auto tmp {0};
        if ((tmp = n % k) == 0) {
            n /= k;
            ++result;
        }
        else {
            result += tmp;
            n -= tmp;
        }
    }

    std::cout << result << std::endl;
}