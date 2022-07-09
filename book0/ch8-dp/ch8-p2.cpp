#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>

auto m {std::unordered_map<int, int> {{1, 0}, {2, 0}, {3, 0}, {4, 1}, {5, 0}}};

auto get_recur(int x) {
    auto it {m.find(x)};
    if (it != m.end()) return 1 + m[x];

    auto cur_min {30'000};

    if (x % 5 == 0)
        cur_min = std::min(cur_min, get_recur(x / 5));

    if (x % 3 == 0)
        cur_min = std::min(cur_min, get_recur(x / 3));

    if (x % 2 == 0)
        cur_min = std::min(cur_min, get_recur(x / 2));
    
    cur_min = std::min(cur_min, get_recur(x - 1));

    m.insert({x, cur_min});

    return 1 + cur_min;
}

auto v {std::vector<int> {1, 1, 1, 2, 1}};

auto get_iter(int x) {
    auto cur_min {30'000};
    for (auto i {6}; i != x + 1; ++i) {
        cur_min = v[i - 1 - 1] + 1;
        if (i % 5 == 0)
            cur_min = std::min(cur_min, 1 + v[i / 5 - 1]);
        if (i % 3 == 0)
            cur_min = std::min(cur_min, 1 + v[i / 3 - 1]);
        if (i % 2 == 0)
            cur_min = std::min(cur_min, 1 + v[i / 2 - 1]);
        v.push_back(cur_min);
    }
    return v[x - 1];
}

int main() {
    auto x {int{}};
    std::cin >> x;

    auto start {std::chrono::high_resolution_clock::now()};
    std::cout << get_recur(x) << std::endl;
    auto end {std::chrono::high_resolution_clock::now() - start};

    std::cout << "Recur: " << std::chrono::duration<double, std::milli> (end).count() << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << get_iter(x) << std::endl;
    end = std::chrono::high_resolution_clock::now() - start;

    std::cout << "Iter: " << std::chrono::duration<double, std::milli> (end).count() << "ms" << std::endl;

    return 0;
}