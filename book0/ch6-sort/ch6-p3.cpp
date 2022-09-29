#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

int main() {
    auto n {int {}};
    auto k {int {}};
    std::cin >> n >> k;
    std::cin >> std::ws;
    auto s1 {std::string {}};
    std::getline(std::cin, s1);
    auto s2 {std::string {}};
    std::getline(std::cin, s2);
    auto ss1 {std::stringstream {s1}};
    auto ss2 {std::stringstream {s2}};

    auto a {std::vector<int> {}};
    auto b {std::vector<int> {}};
    auto temp {int {}};
    for (auto i{0}; i != n; ++i) {
        ss1 >> temp;
        a.push_back(temp);
        ss2 >> temp;
        b.push_back(temp);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end(), std::greater<int>());

    for (auto i {0}; i != k; ++i) {
        std::swap(a[i], b[i]);
    }

    std::cout << std::accumulate(a.begin(), a.end(), 0) << std::endl;

    return 0;
}