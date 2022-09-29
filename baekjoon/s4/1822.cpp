#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto A {int{}};
    auto B {int{}};
    std::cin >> A >> B;

    auto sa {std::unordered_set<int> {}};
    sa.reserve(A);
    auto sb {std::unordered_set<int> {}};
    sb.reserve(B);
    auto sc {std::unordered_set<int> {}};
    sc.reserve(A + B);

    auto temp {int{}};
    for (auto i {0}; i != A; ++i) {
        std::cin >> temp;
        sa.insert(temp);
        sc.insert(temp);
    }

    for (auto i {0}; i != B; ++i) {
        std::cin >> temp;
        sb.insert(temp);
        sc.insert(temp);
    }

    auto result {std::vector<int> {}};
    for (auto it {sc.begin()}; it != sc.end(); ++it) {
        if (!sa.insert(*it).second && sb.insert(*it).second) result.push_back(*it);
    }

    std::sort(result.begin(), result.end());

    std::cout << result.size() << '\n';
    for (auto i : result) std::cout  << i << ' ';

    return EXIT_SUCCESS;
}
