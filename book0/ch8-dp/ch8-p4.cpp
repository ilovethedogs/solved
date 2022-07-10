#include <iostream>
#include <vector>
#include <chrono>

auto dp_v1 {std::vector<size_t> {1, 3}};
size_t get_recur_dp(int n) {
    if (dp_v1.size() >= n) return dp_v1[n - 1];
    dp_v1.push_back((n % 2 == 0) * (get_recur_dp(n - 1) * 2 + 1) + (n % 2 != 0) * ((get_recur_dp(n - 1) - 1) * 2 + 1));
    return dp_v1[n - 1] % 796'796;
}

auto dp_v2 {std::vector<size_t> {1, 3}};
size_t get_iter_dp(int n) {
    if (dp_v2.size() >= n) return dp_v2[n - 1];

    for (auto i {2}; i != n; ++i)
        dp_v2.push_back(((i % 2 != 0) * (dp_v2[i - 1] * 2 + 1) + (i % 2 == 0) * ((dp_v2[i - 1] - 1) * 2 + 1)) % 796'796);

    return dp_v2[n - 1];
}

auto dp_v3 {std::vector<size_t> {1, 3}};
size_t get_optimal(int n) {
    if (dp_v3.size() >= n) return dp_v3[n - 1];

    for (auto i {2}; i != n; ++i)
        dp_v3.push_back((dp_v3[i - 1] + 2 * dp_v3[i - 2]) % 796'796);

    return dp_v2[n - 1];
}

int main() {
    auto n {int{}};
    std::cin >> n;

    auto result {size_t{}};
    auto start {std::chrono::high_resolution_clock::now()};
    result = get_recur_dp(n);
    auto end {std::chrono::high_resolution_clock::now() - start};
    std::cout << std::showpoint << result << " recursive + dp: " << std::chrono::duration<double, std::milli> (end).count() << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    result = get_iter_dp(n);
    end = std::chrono::high_resolution_clock::now() - start;
    std::cout << std::showpoint << result << " iteration + dp: " << std::chrono::duration<double, std::milli> (end).count() << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    result = get_optimal(n);
    end = std::chrono::high_resolution_clock::now() - start;
    std::cout << std::showpoint << result << " optimal: " << std::chrono::duration<double, std::milli> (end).count() << "ms" << std::endl;

    return 0;
}