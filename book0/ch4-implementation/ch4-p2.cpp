#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::string pos;
    std::cin >> pos;

    std::pair<int, int> pos1 {};
    pos1.first = static_cast<int>(pos[0] - 'a' + 1);
    pos1.second = static_cast<int>(pos[1] - '0');

    std::vector<std::pair<int, int>> move {
        {-2, 1},
        {-2, -1},
        {2, 1},
        {2, -1},
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2}
    };

    int result {0};
    for (auto& m : move) {
        std::pair<int, int> tmp {pos1.first + m.first, pos1.second + m.second};
        result += (tmp.first >= 1 && tmp.first <= 8 && tmp.second >= 1 && tmp.second <= 8);
    }
    std::cout << result << std::endl;
}