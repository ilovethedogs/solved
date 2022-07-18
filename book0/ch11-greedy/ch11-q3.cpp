#include <iostream>
#include <string>

int main() {
    auto str {std::string {}};
    std::getline(std::cin, str);

    int result[2] {0, 0};
    auto cur {str[0]};
    for (auto it {std::begin(str) + 1}; it != std::end(str); ++it) {
        if (cur != *it) {
            ++result[cur - '0'];
            cur = *it;
        }
    }
    if (!result[0] || !result[1])
        ++result[cur - '0'];

    auto r {std::min(result[0], result[1])};
    r = std::max(result[0], result[1]) * (r == 0) + r;
    std::cout << r << std::endl;

    return 0;
}