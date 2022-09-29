#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

int main() {
    std::string compressed {};
    std::string chars {"aaaee"};
    char cur_ch {};
    int cur_cnt {0};
    for (auto i : chars) {
        if (cur_ch != i) {
            compressed += cur_ch;
            if (cur_cnt > 1)
                compressed += std::to_string(cur_cnt);
            cur_ch = i;
            cur_cnt = 1;
        }
        else {
            ++cur_cnt;
        }
    }
    compressed += cur_ch;
    if (cur_cnt > 1)
        compressed += std::to_string(cur_cnt);

    std::cout << compressed << std::endl;
    return 0;
}