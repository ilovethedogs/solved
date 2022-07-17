#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

int solution(std::vector<int> food_times, long long k)
{
    int answer = 0;

    auto min_elem{100'000'001};
    auto ft{std::vector<std::pair<int, int>>{}};
    for (auto i{0}; i != food_times.size(); ++i)
    {
        ft.push_back({i + 1, food_times[i]});
        min_elem = std::min(min_elem, food_times[i]);
    }
    k -= min_elem * food_times.size();
    if (k < 0)
        return food_times.size() + k + 1;

    while (min_elem || min_elem != 100'000'001)
    {
        auto temp {int{100'000'001}};
        for (auto i{0}; i != ft.size();)
        {
            if (ft[i].second <= min_elem)
            {
                std::iter_swap(ft.begin() + i, ft.end() - 1);
                ft.pop_back();
            }
            else
            {
                ft[i].second -= min_elem;
                std::cout << ft[i].second << std::endl;
                temp = std::min(temp, ft[i].second);
                ++i;
            }
        }
        min_elem = temp;
        std::cout << "ft\n";
        for (auto& i : ft) {
            std::cout << i.first << ", " << i.second << " | ";
        }
        std::cout << std::endl;
        k -= min_elem * ft.size();
        std::cout << "me: " << min_elem << std::endl;
        std::cout << "k: " << k << std::endl;
        if (k < 0)
            return ft[ft.size() + k].first;
    }
    if (k > 0) return -1;

    return answer;
}

int main() {
    auto v0 {std::vector<int> {3, 1, 2}};
    std::cout << solution(v0, 100) << std::endl;

    return 0;
}