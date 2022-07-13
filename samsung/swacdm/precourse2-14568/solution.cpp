#include <memory>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>

auto db {std::vector<std::unordered_map<std::string, std::map<int, std::set<int>>&>> {}};
auto g1 {std::unique_ptr<std::unordered_map<std::string, std::map<int, std::set<int>>&>> {nullptr}};
auto g2 {std::unique_ptr<std::unordered_map<std::string, std::map<int, std::set<int>>&>> {nullptr}};
auto g3 {std::unique_ptr<std::unordered_map<std::string, std::map<int, std::set<int>>&>> {nullptr}};
auto g1_m {std::unique_ptr<std::map<int, std::set<int>>> {nullptr}};
auto g1_f {std::unique_ptr<std::map<int, std::set<int>>> {nullptr}};
auto g2_m {std::unique_ptr<std::map<int, std::set<int>>> {nullptr}};
auto g2_f {std::unique_ptr<std::map<int, std::set<int>>> {nullptr}};
auto g3_m {std::unique_ptr<std::map<int, std::set<int>>> {nullptr}};
auto g3_f {std::unique_ptr<std::map<int, std::set<int>>> {nullptr}};

auto loc {std::unordered_map<int, int> {}};

void init()
{
    if (g1_m) g1_m.release();
    if (g1_f) g1_f.release();
    if (g2_m) g2_m.release();
    if (g2_f) g2_f.release();
    if (g3_m) g3_m.release();
    if (g3_f) g3_f.release();
    if (g1) g1.release();
    if (g2) g2.release();
    if (g3) g3.release();
    db.clear();

    g1_m = std::make_unique<std::map<int, std::set<int>>> ();
    g1_f = std::make_unique<std::map<int, std::set<int>>> ();
    g2_m = std::make_unique<std::map<int, std::set<int>>> ();
    g2_f = std::make_unique<std::map<int, std::set<int>>> ();
    g3_m = std::make_unique<std::map<int, std::set<int>>> ();
    g3_f = std::make_unique<std::map<int, std::set<int>>> ();

    g1 = std::make_unique<std::unordered_map<std::string, std::map<int, std::set<int>>&>> ();
    g2 = std::make_unique<std::unordered_map<std::string, std::map<int, std::set<int>>&>> ();
    g3 = std::make_unique<std::unordered_map<std::string, std::map<int, std::set<int>>&>> ();

    g1->insert({"male", *g1_m});
    g1->insert({"female", *g1_f});
    g2->insert({"male", *g2_m});
    g2->insert({"female", *g2_f});
    g3->insert({"male", *g3_m});
    g3->insert({"female", *g3_f});

    db.push_back(*g1);
    db.push_back(*g2);
    db.push_back(*g3);

    loc.clear();
}

int add(int mId, int mGrade, char mGender[7], int mScore)
{
    std::string gender {mGender};
    auto temp {db[mGrade - 1].at(gender).insert({mScore, {mId}})};
    if (!temp.second) {
        temp.first->second.insert(mId);
    }
    loc.insert({mId, ((static_cast<int>(mGender[0]) << 22) | (mGrade << 20) | mScore)});
    auto it {std::end(db[mGrade - 1].at(gender))};
    std::advance(it, -1);
    auto result {std::end(it->second)};
    std::advance(result, -1);
    return *result;
}

int remove(int mId)
{
    auto it {loc.find(mId)};
    if (it == std::end(loc)) {
        return 0;
    }
    else {
        auto location {loc[mId]};
        int gen_num {(location & 0x1FC00000) >> 22};
        int grade {(location & 0x300000) >> 20};
        int score {location & 0x7FFFF};
        auto gender {std::string{}};
        switch (gen_num) {
            case 'm':
                gender = "male";
                break;
            case 'f':
                gender = "female";
                break;
        }
        auto& m {db[grade - 1].at(gender)};
        auto vit {m.find(score)};
        vit->second.erase(mId);
        loc.erase(mId);
        if (vit->second.empty())
            m.erase(score);
        if (m.empty()) return 0;

        auto& v {std::begin(m)->second};
        return *std::begin(v);
    }
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore)
{
    auto result {std::pair<int, int> {1'000'000'001, 300'001}};
    for (auto i {0}; i != mGradeCnt; ++i) {
        for (auto j {0}; j != mGenderCnt; ++j) {
            auto gender {std::string{mGender[j]}};
            auto& m {db[mGrade[i] - 1].at(gender)};
            auto it {m.lower_bound(mScore)};
            if (it == std::end(m) || it->first > result.second) {
                continue;
            }
            else {
                auto min_id {*std::begin(it->second)};

                bool yes {result.second == it->first && result.first > min_id || result.second > it->first};
                result.first = min_id * yes + result.first * !yes;
                result.second = it->first * (result.second > it->first) + result.second * (result.second <= it->first);
            }
        }
    }
    if (result.first == 1'000'000'001) return 0;
    return result.first;
}