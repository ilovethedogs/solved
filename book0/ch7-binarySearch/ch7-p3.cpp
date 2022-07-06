#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>

size_t sum(std::vector<size_t>& v, int mid) {
    auto it {v.begin()};
    std::advance(it, mid);
    return std::accumulate(it, v.end(), 0, std::plus<>()) - (v.size() - mid) * v[mid];
}

size_t bin_search(std::vector<size_t>& v, size_t m) {
    auto low {size_t{}};
    auto high {size_t{v.size() - 1}};

    auto mid {size_t{}};
    while (low != high) {
        mid = (low + high) / 2;
        auto s {sum(v, mid)};
        if (s == m) return v[mid];
        else if (s < m) low = mid + 1;
        else high = mid - 1;
    }

    auto s {sum(v, low)};
    std::cout << s << std::endl;
    if (s == m) {
        return v[low];
    } 
    else if (s < m) {
        auto temp_sum {size_t{}};
        for (auto i {v[low]}; i != v[low - 1] - 1; --i) {
            temp_sum = 0;
            for (auto j {low}; j != v.size(); ++j) {
                temp_sum += v[j] - i;
            }
            if (temp_sum == m) return i;
        }
    }
    else {
        auto temp_sum {size_t{}};
        for (auto i {v[low]}; i != v[low + 1] + 1; ++i) {
            temp_sum = 0;
            for (auto j {low}; j != v.size(); ++j) {
                temp_sum += v[j] - i;
            }
            if (temp_sum == m) return i;
        }
    }
    return 0;
}

int main() {
    auto n {size_t{0}};
    auto m {size_t{0}};
    std::cin >> n >> m;
    std::cin >> std::ws;

    auto s {std::string{}};
    std::getline(std::cin, s);
    auto ss {std::stringstream {s}};
    auto v {std::vector<size_t> {}};
    auto temp {size_t{}};
    while (ss.good()) {
        ss >> temp;
        v.push_back(temp);
    }
    std::sort(v.begin(), v.end());

    std::cout << bin_search(v, m) << std::endl;
    
    return 0;
}