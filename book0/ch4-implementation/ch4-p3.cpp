#include <iostream>
#include <utility>
#include <vector>
#include <array>

int main()
{
    int n, m{};
    std::cin >> n >> m;

    std::pair<int, int> initPos{};
    int curDir{};
    std::cin >> initPos.first >> initPos.second >> curDir;

    char map[2 * n * m + 1]{};
    std::cin >> std::ws;
    std::cin.getline(map, 2 * n * m, '#');

    int delta[4] {-2 * n, 2, 2 * n, -2};
    int goback[4] {2, 2, -2, -2};

    int result{1};
    int cur = initPos.first * 2 * n + initPos.second * 2;
    map[cur] = '2';
    while (true) {
    keepgoing:
        for (int dir{(curDir + 1) % 4}; dir % 4 != curDir; ++dir)
        {
            int dirPos{cur + delta[dir]};
            switch (map[dirPos])
            {
            case '1':
            case '2':
                continue;
            case '0':
                curDir = dir;
                cur = dirPos;
                ++result;
                map[cur] = '2';
                goto keepgoing;
            }
        }
        // go back
        int backPos{cur + delta[curDir]};
        if (backPos < 0 || backPos >= 2 * n * m)
        {
            break;
        }

        switch (map[backPos])
        {
        case '1':
            goto done;
        case '0':
            ++result;
            map[backPos] = '2';
        case '2':
            cur = backPos;
            curDir += goback[curDir];
            goto keepgoing;
        }
    }

done:
    std::cout << result << std::endl;

    return 0;
}