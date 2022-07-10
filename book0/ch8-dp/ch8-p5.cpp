#include <iostream>
#include <vector>

int unsigned get(std::vector<int>& v, int n, int m) {
    auto dp_v {std::vector<int> (m + 1, 10'001)};
    dp_v[0] = 0;
    for (auto i : v) {
        for (auto j {i}; j < dp_v.size(); ++j) {
            if (j % i == 0) {
                dp_v[j] = std::min(dp_v[j], j / i);
            }   
            else if (dp_v[j - i] != 10'001) {
                dp_v[j] = std::min(dp_v[j], dp_v[j - i] + 1);
            }
        }
    }
    return *(dp_v.end() - 1);
}

int main() {
    auto n {int{}};
    auto m {int{}};
    std::cin >> n >> m;
    std::cin >> std::ws;
    auto temp {int{}};
    auto v {std::vector<int> {}};
    for (auto i {0}; i != n; ++i) {
        std::cin >> temp;
        v.push_back(temp);
    }
        
    std::cout << get(v, n, m) << std::endl;
    return 0; 
}