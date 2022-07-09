#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    auto n {int{}};
    std::cin >> n >> std::ws;
    auto s {std::string{}};
    std::getline(std::cin, s);
    auto ss {std::stringstream {s}};
    auto v {std::vector<int> {}};
    auto temp {int{}};
    while (ss.good()) {
        ss >> temp;
        v.push_back(temp);
    }

    
}