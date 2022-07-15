#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <cstdio>

int find_parent(std::vector<int> &v, int x)
{
    if (v[x] != x)
        v[x] = find_parent(v, v[x]);
    auto y{x};
    while (v[y] != y)
        y = v[y];
    v[x] = y;
    return v[x];
}

void union_parent(std::vector<int> &v, int a, int b)
{
    a = find_parent(v, a);
    b = find_parent(v, b);
    a > b ? v[a] = b : v[b] = a;
}

int main()
{
    auto n{int{}};
    auto m{int{}};
    std::cin >> n >> m;

    auto a{int{}};
    auto b{int{}};
    auto c{int{}};
    auto v{std::vector<int>(n + 1)};
    for (auto i{0}; i != n + 1; ++i)
        v[i] = i;

    auto mm{std::multimap<int, std::pair<int, int>>{}};
    for (auto i{0}; i != m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        mm.insert({c, {a, b}});
    }

    auto result{0};
    auto max_elem{0};
    for (auto it{std::begin(mm)}; it != std::end(mm); std::advance(it, 1))
    {
        if (find_parent(v, it->second.first) != find_parent(v, it->second.second))
        {
            union_parent(v, it->second.first, it->second.second);
            result += it->first;
            max_elem = std::max(max_elem, it->first);
        }
    }

    std::cout << (result - max_elem) << std::endl;
    return 0;
}