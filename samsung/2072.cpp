#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    auto n {int{}};
    std::cin >> n;
    char lf[1] {};
    std::cin.getline(lf, 1);
    for (auto i {0}; i != n; ++i) {
        auto s {std::string{}};
        std::getline(std::cin, s);
        auto ss {std::stringstream {s}};
        auto temp {int{}};
        auto v {std::vector<int> {}};
        while (ss) {
            ss >> temp;
            v.push_back(temp);
        }
        auto result {int {0}};
        for (auto j : v) {
            result += j * (j % 2 == 1);
        }
        std::cout << "#" << i + 1 << " " << result << std::endl;
    }
    return 0;
}
