#include <iostream>
#include <vector>
#include <unordered_map>
std::vector<int> v {};
std::unordered_map<int, std::unordered_map<int, int>> um {};

int doe_or_die(int num, int idx) {
    if (um.find(num) != um.end() && um[num].find(idx) != um[num].end()) return um[num][idx];

    if (idx == v.size() - 2) {
        if (num == 0 || v[idx + 1] == 0 || num == v[idx + 1]) return (um[num][idx] = 1);
        else return (um[num][idx] = 2);
    }

    if (num == 0) return (um[num][idx] = doe_or_die(v[idx + 1], idx + 1));
    if (num > v[idx + 1])
        return (um[num][idx] = std::min(2 + doe_or_die(0, idx + 1), 1 + doe_or_die(v[idx + 1], idx + 1)));
    else if (num < v[idx + 1])
        return (um[num][idx] = std::min(1 + doe_or_die(v[idx + 1] - num, idx + 1), 1 + doe_or_die(v[idx + 1], idx + 1)));
    else
        return (um[num][idx] = std::min(1 + doe_or_die(0, idx + 1), 1 + doe_or_die(v[idx + 1], idx + 1)));
}

int main() {
    auto N {int{}};
    std::cin >> N;
    auto temp {int{}};
    v.reserve(N);
    for (auto i {0}; i != N; ++i) {
        std::cin >> temp;
        v.push_back(temp);
    }

    std::cout << doe_or_die(v[0], 0) << '\n';

    return EXIT_SUCCESS;
}
