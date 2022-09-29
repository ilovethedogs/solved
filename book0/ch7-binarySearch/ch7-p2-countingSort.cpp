
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    // get input
    auto n {int{}};
    std::cin >> n;
    std::cin >> std::ws;
    auto s {std::string{}};
    std::getline(std::cin, s);
    auto ss {std::stringstream {s}};
    auto temp {int{}};
    auto v_n {std::vector<bool> (1'000'000)};
    while (ss.good()) {
        ss >> temp;
        v_n[temp] = true;
    }
    auto m {int{}};
    std::cin >> m;
    std::cin >> std::ws;
    s.clear();
    std::stringstream{}.swap(ss);
    std::getline(std::cin, s);
    ss.str(s);
    auto v_m {std::vector<int> {}};
    while (ss.good()) {
        ss >> temp;
        v_n[temp] == true ? std::cout << "yes" : std::cout << "no";
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}