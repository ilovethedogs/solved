#include <iostream>
#include <vector>

auto qv {std::vector<bool> (250'001, false)};
auto visited {std::vector<bool> (250'001, false)};
auto prev_node {std::vector<int> (250'001, -1)};

auto prev_set {std::vector<int> {}};

auto parent {std::vector<int> (250'001, 0)};
auto num_of_family {std::vector<size_t> (250'001, 1)};

int root(int x) {
    if (x == parent[x]) return x;
    return parent[x] = root(parent[x]);
}

size_t connect(int a, int b) {
    a = root(a);
    b = root(b);

    if (num_of_family[a] < num_of_family[b]) std::swap(a, b);
    parent[b] = a;
    auto ret {num_of_family[a] * num_of_family[b]};
    num_of_family[a] += num_of_family[b];
    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    std::cin >> N;
    auto t1 {int{}};
    auto t2 {int{}};
    auto v {std::vector<std::vector<int>> (N + 1, std::vector<int> {})};
    for (auto i {1}; i != N; ++i)
    {
        std::cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
        parent[i] = i;
    }
    parent[N] = N;

    prev_node[1] = 0;
    for (auto i {0}; i != N; ++i)
    {
        auto st {std::vector<int> {}};
        st.reserve(N);
        st.push_back(i);
        while (!st.empty())
        {
            auto cur {st.back()};
            st.pop_back();

            visited[cur] = true;
            for (auto j : v[cur])
                if (!visited[j]) {
                    prev_node[j] = cur;
                    st.push_back(j);
                }
        }
    }

    auto Q {int{}};
    std::cin >> Q;
    for (auto i {0}; i != Q; ++i)
    {
        for (auto n : prev_set) {
            qv[n] = false;
            parent[n] = n;
            num_of_family[n] = 1;
        }

        prev_set.clear();

        std::cin >> t1;
        for (auto j {0}; j != t1; ++j)
        {
            std::cin >> t2;
            qv[t2] = true;
            prev_set.push_back(t2);
        }

        auto result {size_t{}};
        for (auto j {0}; j != t1; ++j) {
            if (!qv[prev_node[prev_set[j]]]) continue;
            result += connect(prev_set[j], prev_node[prev_set[j]]);
        }
        std::cout << result << '\n';
    }

    return EXIT_SUCCESS;
}
