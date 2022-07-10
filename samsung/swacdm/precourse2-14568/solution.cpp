#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

auto g1_m {std::map<int, int> {}};
auto g1_f {std::map<int, int> {}};
auto g2_m {std::map<int, int> {}};
auto g2_f {std::map<int, int> {}};
auto g3_m {std::map<int, int> {}};
auto g3_f {std::map<int, int> {}};
auto g1 {std::map<std::string, std::map<int, int>> {{"male", g1_m}, {"female", g1_f}}};
auto g2 {std::map<std::string, std::map<int, int>> {{"male", g2_m}, {"female", g2_f}}};
auto g3 {std::map<std::string, std::map<int, int>> {{"male", g3_m}, {"female", g3_f}}};
auto db {std::vector<std::map<std::string, std::map<int, int>>> {g1, g2, g3}};

auto loc {std::map<int, int> {}};

void init()
{
    g1_m.clear();
    g1_f.clear();
    g2_m.clear();
    g2_f.clear();
    g3_m.clear();
    g3_f.clear();
}

int add(int mId, int mGrade, char mGender[7], int mScore)
{
    std::string gender {mGender};
    db[mGrade - 1][gender].insert({mId, mScore});
    loc.insert({mId, static_cast<int>(mGender[0]) * 10 + mGrade});
    return std::max_element(std::begin(db[mGrade - 1][gender]), std::end(db[mGrade - 1][gender]), 
                            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                                return a.second < b.second || (a.second == b.second && a.first < b.first);
                            })->first;
}

int remove(int mId)
{
    auto it {loc.find(mId)};
    if (it == std::end(loc)) {
        return 0;
    }
    else {
        auto location {loc[mId]};
        int grade {location % 10};
        location /= 10;
        auto gender {std::string{}};
        switch (location) {
            case 'm':
                gender = "male";
                break;
            case 'f':
                gender = "female";
                break;
            default:
                ;
        }
        db[grade - 1][gender].erase(mId);
        loc.erase(mId);
        if (db[grade - 1][gender].size() == 0)
            return 0;
        return std::min_element(std::begin(db[grade - 1][gender]), std::end(db[grade - 1][gender]), 
                                [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                                    return a.second < b.second || (a.second == b.second && a.first < b.first);
                                })->first;
    }
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore)
{
    auto result {std::pair<int, int> {1'000'000'001, 300'001}};
    for (auto i {0}; i != mGradeCnt; ++i) {
        for (auto j {0}; j != mGenderCnt; ++j) {
            auto gender {std::string{mGender[j]}};
            auto temp_db {std::map<int, int> {}};
            std::copy_if(std::begin(db[mGrade[i] - 1][mGender[j]]), std::end(db[mGrade[i] - 1][mGender[j]]), std::inserter(temp_db, temp_db.end()), 
                         [mScore](const std::pair<int, int>& a){
                            return a.second > mScore;
                         });
            auto temp_result {std::pair<int, int> {*std::min_element(std::begin(temp_db), std::end(temp_db),
                                            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                                                    return a.second < b.second || (a.second == b.second && a.first < b.first);
                                            })}};
            result = std::min(result, temp_result, 
                              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                                return a.second < b.second || (a.second == b.second && a.first < b.first);
                              });
        }
    }
    return result.first;
}