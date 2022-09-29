#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    auto M {int{}};
    std::cin >> N >> M;

    auto set_a {std::unordered_set<std::string> {}};
    set_a.reserve(N);
    auto set_b {std::unordered_set<std::string> {}};
    set_b.reserve(M);
    auto set_c {std::unordered_set<std::string> {}};
    set_c.reserve(N + M);

    auto temp {std::string{}};
    for (auto i {0}; i != N; ++i) {
        std::cin >> temp;
        set_a.insert(temp);
        set_c.insert(temp);
    }

    for (auto i {0}; i != N; ++i) {
        std::cin >> temp;
        set_b.insert(temp);
        set_c.insert(temp);
    }

    auto result {std::vector<std::string> {}};
    for (auto it {set_c.begin()}; it != set_c.end(); ++it) {
        if (!set_a.insert(*it).second && !set_b.insert(*it).second) result.push_back(*it);
    }

    std::sort(result.begin(), result.end());

    std::cout << result.size() << '\n';
    for (auto& s : result) std::cout << s << '\n';


    return EXIT_SUCCESS;
}
