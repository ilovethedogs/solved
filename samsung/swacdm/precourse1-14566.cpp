#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    auto tt {int{}};
    std::cin >> tt >> std::ws;
    
    for (auto t {0}; t != tt; ++t) {
        auto n {int{}};
        std::cin >> n >> std::ws;
        auto temp {int{}};
        auto m {std::vector<int> {}};
        for (auto i {0}; i != n * n; ++i) {
            std::cin >> temp;
            m.push_back(temp);
        }

        auto start {*std::min_element(m.begin(), m.end())};
        auto end {*std::max_element(m.begin(), m.end())};
        auto result {int{1}};
        for (auto i {start}; i != end; ++i) {
            auto cur_m {std::vector<int> (m)};
            auto qu {std::queue<int> {}};
            auto cur_result {int{}};
            for (auto j {0}; j != cur_m.size(); ++j) {
                // cur_m[j] <= i : not accessible
                // cur_m[j] < 0  : already visited 
                if (cur_m[j] > i) {
                    ++cur_result;
                    qu.emplace(j);
                    cur_m[j] *= -1;
                    while (!qu.empty()) {
                        auto cur {int{qu.front()}}; qu.pop();

                        if (cur - 1 >= (cur / n) * n && cur_m[cur - 1] > i) {
                            cur_m[cur - 1] *= -1;
                            qu.emplace(cur - 1);
                        }
                        if (cur + 1 < ((cur / n) + 1) * n && cur_m[cur + 1] > i) {
                            cur_m[cur + 1] *= -1;
                            qu.emplace(cur + 1);
                        }
                        if (cur + n < n * n && cur_m[cur + n] > i){ 
                            cur_m[cur + n] *= -1;
                            qu.emplace(cur + n);
                        }
                        if (cur - n >= 0 && cur_m[cur - n] > i) {
                            cur_m[cur - n] *= -1;
                            qu.emplace(cur - n);
                        }
                    }
                }
            }
            result = std::max(result, cur_result);
        }
        std::cout << "#" << t + 1 << " " << result << std::endl;
    }
    return 0;
}
