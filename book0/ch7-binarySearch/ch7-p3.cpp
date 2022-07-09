#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>

size_t ddeock(std::vector<size_t>& v, size_t mid, size_t sum) {
    for (auto& i : v) {
        sum -= i * (i < mid) + mid * (i >= mid);
    }
    return sum;
}

size_t bin_search(std::vector<size_t>& v, size_t m) {
    auto low {*std::min_element(v.begin(), v.end())};
    auto high {*std::max_element(v.begin(), v.end())};

    auto sum {std::accumulate(v.begin(), v.end(), 0, std::plus<>())};
    auto mid {size_t{}};
    while (low <= high) {
        mid = (low + high) / 2;
        auto s {ddeock(v, mid, sum)};
        if (s == m) return mid;
        else if (s > m) low = mid + 1;
        else high = mid - 1;
    }

    return mid;
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

    std::cout << bin_search(v, m) << std::endl;
    
    return 0;
}