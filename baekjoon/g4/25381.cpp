#include <iostream>
#include <set>

int main() {
    auto len {0};
    auto c {int{}};
    auto apos {std::set<int> {}};
    auto bpos {std::set<int> {}};
    auto cpos {std::set<int> {}};
    while ((c = getchar_unlocked()) <= 'C' && c >= 'A') {
        ++len;
        switch(c) {
            case 'A':
                apos.insert(len);
                break;
            case 'B':
                bpos.insert(len);
                break;
            case 'C':
                cpos.insert(len);
                break;
        }
    }

    auto result {0};
    while (!cpos.empty() && !bpos.empty()) {
        auto bit {bpos.begin()};
        auto cit {cpos.begin()};
        for (; cit != cpos.end() && *bit > *cit; ++cit) ;
        if (cit != cpos.end()) {
            bpos.erase(bit);
            cpos.erase(cit);
            ++result;
        }
        else {
            break;
        }
    }

    while (!bpos.empty() && !apos.empty()) {
        auto ait {apos.begin()};
        auto bit {bpos.begin()};
        for (; bit != bpos.end() && *ait > *bit; ++bit) ;
        if (bit != bpos.end()) {
            apos.erase(ait);
            bpos.erase(bit);
            ++result;
        }
        else {
            break;
        }
    }

    std::cout << result;

    return EXIT_SUCCESS;
}

