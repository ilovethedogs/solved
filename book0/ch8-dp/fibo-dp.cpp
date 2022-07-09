#include <iostream>
#include <chrono>
#include <vector>

uint64_t nth_fibo_iteration(size_t n) {
    auto n1 {0};
    auto n2 {1};
    for (auto i {0}; i != static_cast<int>(n / 2); ++i) {
        n1 += n2;
        n2 += n1;
    }
    auto ret {n % 2 == 0};
    return n1 * ret + n2 * !ret;
}

uint64_t nth_fibo_recursive(size_t n) {
    switch (n) {
        case 0: return 0;
        case 1: return 1;
        default:
            return nth_fibo_recursive(n - 1) + nth_fibo_recursive(n - 2);
    }
}

std::vector<uint64_t> fibo_recur_v {0, 1};

uint64_t nth_fibo_recursive_dp(size_t n) {
    if (fibo_recur_v.size() >= n + 1) return fibo_recur_v[n];

    fibo_recur_v.push_back(nth_fibo_recursive_dp(n - 1) + nth_fibo_recursive_dp(n - 2));
    return fibo_recur_v[n];
}

std::vector<uint64_t> fibo_iter_v {0, 1};

uint64_t nth_fibo_iteration_dp(size_t n) {
    if (fibo_iter_v.size() >= n + 1) return fibo_iter_v[n];

    for (auto i {fibo_iter_v.size()}; i != n + 1; ++i) {
        fibo_iter_v.push_back(fibo_iter_v[i - 1] + fibo_iter_v[i - 2]);
    }  

    return fibo_iter_v[n];
}

int main() {
    auto n {35};

    auto start {std::chrono::high_resolution_clock::now()};
    std::cout << nth_fibo_iteration(n) << " ";
    auto diff {std::chrono::high_resolution_clock::now() - start};

    std::cout << "iteration: " <<  std::chrono::duration<double, std::milli> (diff).count() 
	          << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << nth_fibo_recursive(n) << " ";
    diff = std::chrono::high_resolution_clock::now() - start;

    std::cout << "recursive: " <<  std::chrono::duration<double, std::milli> (diff).count() 
	          << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << nth_fibo_recursive_dp(n) << " ";
    diff = std::chrono::high_resolution_clock::now() - start;

    std::cout << "recursive + dp: " <<  std::chrono::duration<double, std::milli> (diff).count() 
	          << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << nth_fibo_iteration_dp(n) << " ";
    diff = std::chrono::high_resolution_clock::now() - start;

    std::cout << "iteration + dp: " <<  std::chrono::duration<double, std::milli> (diff).count() 
            << "ms" << std::endl;

    for (auto i {0}; i != 11; ++i) std::cout << nth_fibo_iteration_dp(i) << " ";
    std::cout << std::endl;
    return 0;
}