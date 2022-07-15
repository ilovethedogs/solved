#include <iostream>
#include <vector>

int find_parent(std::vector<int>& v, int x) {
    if (v[x] != x)
        v[x] = find_parent(v, v[x]);
    return v[x];
}

void union_parent(std::vector<int>& v, int a, int b) {
    a = find_parent(v, a);
    b = find_parent(v, b);
    a < b ? v[b] = a : v[a] = b;
}

int main() {
    auto n {int{}};
    auto m {int{}};
    std::cin >> n >> m >> std::ws;

    auto v {std::vector<int> (n + 2)};
    for (auto i {0}; i != n + 2; ++i) v[i] = i;

    auto op {int{}};
    auto a {int{}};
    auto b {int{}};
    for (auto i {0}; i != m; ++i) {
        std::cin >> op >> a >> b;
        switch (op) {
            case 0:
                union_parent(v, a, b);
                break;
            case 1:
                if (find_parent(v, a) == find_parent(v, b))
                    std::cout << "YES" << std::endl;
                else
                    std::cout << "NO" << std::endl;
                break;
        }
    }
    return 0;
}