#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    auto n {int{}};
    std::cin >> n >> std::ws;
    auto v {std::vector<int> {}};
    auto temp {int{}};
    for (auto i {0}; i != n; ++i) {
        std::cin >> temp;
        v.push_back(temp);
    }

    std::sort(v.begin(), v.end());

    auto result {1};
    for (auto i : v) {
        if (result < i) break;
        result += i;
    }

    std::cout << result << std::endl;
    
    return 0;
}