#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <array>


int main() {
    auto n {int {}};
    std::cin >> n;
    auto v {std::vector<std::pair<std::string, int>> {}};
    auto te {std::string {}};
    auto mp {int {}};
    for (auto i {0}; i != n; ++i) {
        std::cin >> te >> mp;
        v.emplace_back(te, mp);
    }
    auto cnt {std::vector<std::vector<std::string>>(100)};
    for (auto& i : v) {
        cnt[i.second].push_back(i.first);
    }

    for (auto& i : cnt) {
        if (i.size() != 0) {
            for (auto& j : i) std::cout << j << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}