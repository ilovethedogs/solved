#include <iostream>
#include <vector>

int main() {
    auto n {int{}};
    std::cin >> n >> std::ws;

    auto v {std::vector<int> {}};
    auto temp {0};
    for (auto i {0}; i != n; ++i) {
        std::cin >> temp;
        v.push_back(temp);
    } 

    // performing counting sort
    auto cnt {std::vector<int> (100'001, 0)};
    for (auto i : v) {
        ++cnt[i];
    }
    auto sorted_v {std::vector<int> {}};
    for (auto i {100'000}; i != 0; --i) {
        while (cnt[i]--)
            sorted_v.push_back(i);
    }
    // done

    auto result {0};
    for (auto i {0}; i < sorted_v.size(); ++i) {
        auto cur {sorted_v[i]};
        while (--cur) ++i;
        if (i < sorted_v.size()) ++result;
        else break;
    }
    std::cout << result << std::endl;

    return 0;
}