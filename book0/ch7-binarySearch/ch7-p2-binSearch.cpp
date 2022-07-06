#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

bool bin_search(std::vector<int>& v, int key) {
    auto low {int{0}};
    auto high {int{v.size() - 1}};

    while (low <= high) {
        auto mid {int{(low + high) / 2}};

        if (v[mid] == key) return true;
        else if (v[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    // get input
    auto n {int{}};
    std::cin >> n;
    std::cin >> std::ws;
    auto s {std::string{}};
    std::getline(std::cin, s);
    auto ss {std::stringstream {s}};
    auto temp {int{}};
    auto v_n {std::vector<int> {}};
    while (ss.good()) {
        ss >> temp;
        v_n.push_back(temp);
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
        v_m.push_back(temp);
    }

    std::sort(v_n.begin(), v_n.end());
    auto result {bool{true}};
    for (auto i : v_m) {
        bin_search(v_n, i) ? std::cout << "yes" : std::cout << "no";
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}