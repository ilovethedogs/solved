#include <iostream>
#include <string>
#include <utility>

int main()
{
    int n;
    std::cin >> n;
    std::cin.get();
    std::string sequence;
    std::getline(std::cin, sequence);

    std::pair<int, int> curPos{1, 1};
    for (auto i{0}; i != sequence.size() + 1; i += 2)
    {
        curPos.second += 1 * (sequence[i] == 'R' && curPos.second < (n - 1)) +
                        -1 * (sequence[i] == 'L' && curPos.second > 1);
        curPos.first += -1 * (sequence[i] == 'U' && curPos.first > 1) +
                         1 * (sequence[i] == 'D' && curPos.first < (n - 1));
    }
    std::cout << curPos.first << " " << curPos.second << std::endl;

    return 0;
}