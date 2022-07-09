#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <utility> 
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

auto um1 {std::unordered_map<std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator>, size_t> {}};
size_t get_recur_dp(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    if (end <= begin || begin >= end) return 0;
    auto iter {um1.find({begin, end})};
    if (iter != um1.end()) return um1[{begin, end}];

    auto result {size_t{}};
    for (auto it {begin}; it != end; ++it) {
        result = std::max(result, *it + get_recur_dp(begin, it - 1) + get_recur_dp(it + 2, end));
    }
    um1.insert({{begin, end}, result});
    return result;
} 

size_t get_iter(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    auto result {size_t{}};
}

auto um2 {std::unordered_map<std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator>, size_t> {}};

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

    start = std::chrono::high_resolution_clock::now();
    result = get_recur_dp(std::begin(test_v), std::end(test_v));
    end = std::chrono::high_resolution_clock::now() - start;
    std::cout << result << " ";
    std::cout << "recursive + dp: " << std::showpoint << std::chrono::duration<double, std::milli> (end).count() << "ms" << std::endl;

    return 0;
}