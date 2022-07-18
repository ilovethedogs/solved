#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>

int main() {
    auto n {int{}};
    std::cin >> n >> std::ws;
    auto v {std::vector<std::pair<int, int>> (n + 1)};
    auto mp {std::map<int, std::vector<int>> {}};
    for (auto i {1}; i != n + 1; ++i) mp.insert({i, {}});
    auto a {int{}};
    for (auto i {1}; i != n + 1; ++i) {
        std::cin >> a;
        v[i].first = a;
        v[i].second = 0;

        auto b {int{}};
        std::cin >> b;
        while (b != -1) {
            ++v[i].second;
            mp[b].push_back(i);
            std::cin >> b;
        }
    }

    auto q {std::queue<int> {}};
    for (auto i {1}; i != n + 1; ++i) if (v[i].second == 0) q.emplace(i);
    while (!q.empty()) {
        auto cur {q.front()};
        q.pop();

        std::cout << v[cur].first << "\n";

        for (auto i : mp[cur]) {
            --v[i].second;
            if (v[i].second == 0) {
                v[i].first += v[cur].first;
                q.emplace(i);
            }

        }
    }
    std::cout << std::endl;

    return 0;
}