#include <iostream>
#include <utility>
#include <vector>
#include <array>

int main() {
    int n, m {};
    std::cin >> n >> m;

    std::pair<int, int> initPos {};
    int curDir {};
    std::cin >> initPos.first >> initPos.second >> curDir;

    std::cin.get();
    char map[2 * n * m + 1] {};
    std::cin.getline(map, 2 * n * m, '#');
    
    int result {1};
    int cur = initPos.first * 2 * n + initPos.second * 2;
    map[cur] = '2';
    while (true) {
        keepgoing:
        for (int dir {curDir}; dir % 4 != curDir; ++dir) {
            int dirPos {cur + (-2 * n) * (dir == 0) + 2 * (dir == 1) + (2 * n) * (dir == 2) + (-2) * (dir == 3)};
            switch (dirPos) {
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
        int backPos {cur + (-2 * n) * (curDir == 0) + 2 * (curDir == 1) + (2 * n) * (curDir == 2) + (-2) * (curDir == 3)};
        if (backPos < 0 || backPos >= 2 * n * m) {
            break;        
        }

        switch (map[backPos]) {
            case 1: goto done;
            case 0: ++result; map[backPos] = '2';
            case 2: cur = backPos; curDir += 2 * (curDir == 0 || curDir == 1) - 2 * (curDir == 2 || curDir == 3); goto keepgoing;
        }
    }
       
    done:
    std::cout << result << std::endl;

    return 0;
}