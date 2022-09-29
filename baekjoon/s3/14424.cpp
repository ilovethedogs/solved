#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    auto M {int{}};
    std::cin >> N >> M;

    auto s {std::unordered_set<std::string> {}};
    auto temp {std::string{}};
    for (auto i {0}; i != N; ++i) {
        std::cin >> temp;
        s.insert(temp);
    }

    auto result {0};
    for (auto i {0}; i != M; ++i) {
        std::cin >> temp;
        if (s.find(temp) != s.end()) ++result;
    }

    std::cout << result;

    return EXIT_SUCCESS;
}
