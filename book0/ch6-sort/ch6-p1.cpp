#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    auto n {int {}};
    std::cin >> n;
    char lf[1] {};
    std::cin.getline(lf, 1);
    auto v {std::vector<int> {}};
    auto temp {int {}};
    for (auto i {0}; i != n; ++i) {
        std::cin >> temp; 
        v.push_back(temp);
    }
    
    std::sort(v.begin(), v.end(), std::greater<int>()); 

    for (auto i : v) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}