#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <random>
#include <chrono>

auto recur {size_t{}};
size_t get_recur(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    std::cout << recur << "th" << std::endl;
    if (end <= begin || begin >= end) return 0;
    auto result {size_t{}};
    for (auto it {begin}; it != end; ++it) {
        result = std::max(result, *it + get_recur(begin, it - 1) + get_recur(it + 2, end));
    }
    return result;
}

size_t get_optimal(std::vector<int>& v) {
    auto dp_v {std::vector<int> {}};
    dp_v.push_back(v[0]);
    dp_v.push_back(std::max(v[0], v[1]));
    for (auto it {std::begin(v) + 2}; it != std::end(v); ++it) {
        dp_v.push_back(std::max(*(it - 1), *(it - 2) + *it));
    }
    return *(std::end(v) - 1);
}

int main() {
    /*
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

    std::cout << get(std::begin(v), std::end(v)) << std::endl;
    */

    auto rd {std::random_device{}};
    auto mtgen {std::mt19937 {rd()}};
    auto ud {std::uniform_int_distribution<>(0, 1000)};
    auto test_v {std::vector<int> {}};
    for (auto i {0}; i < 20; ++i) test_v.push_back(ud(mtgen));

    auto result {size_t{}};

    auto start {std::chrono::high_resolution_clock::now()};
    result = get_recur(std::begin(test_v), std::end(test_v));
    auto end {std::chrono::high_resolution_clock::now() - start};
    std::cout << result << " ";
    std::cout << "recursive: " << std::showpoint << std::chrono::duration<double, std::milli> (end).count() << "ms" << std::endl;

    return 0;
}