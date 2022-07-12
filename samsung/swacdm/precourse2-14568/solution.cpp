#include <memory>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <string>

auto db {std::vector<std::map<std::string, std::map<int, std::vector<int>>&>> {}};
auto g1 {std::unique_ptr<std::map<std::string, std::map<int, std::vector<int>>&>> {nullptr}};
auto g2 {std::unique_ptr<std::map<std::string, std::map<int, std::vector<int>>&>> {nullptr}};
auto g3 {std::unique_ptr<std::map<std::string, std::map<int, std::vector<int>>&>> {nullptr}};
auto g1_m {std::unique_ptr<std::map<int, std::vector<int>>> {nullptr}};
auto g1_f {std::unique_ptr<std::map<int, std::vector<int>>> {nullptr}};
auto g2_m {std::unique_ptr<std::map<int, std::vector<int>>> {nullptr}};
auto g2_f {std::unique_ptr<std::map<int, std::vector<int>>> {nullptr}};
auto g3_m {std::unique_ptr<std::map<int, std::vector<int>>> {nullptr}};
auto g3_f {std::unique_ptr<std::map<int, std::vector<int>>> {nullptr}};

auto loc {std::map<int, int> {}};

void init()
{
    if (g1_m != nullptr) g1_m.release();
    if (g1_f != nullptr) g1_f.release();
    if (g2_m != nullptr) g2_m.release();
    if (g2_f != nullptr) g2_f.release();
    if (g3_m != nullptr) g3_m.release();
    if (g3_f != nullptr) g3_f.release();
    if (g1 != nullptr) g1.release();
    if (g2 != nullptr) g2.release();
    if (g3 != nullptr) g3.release();
    db.clear();

    g1_m = std::make_unique<std::map<int, std::vector<int>>> ();
    g1_f = std::make_unique<std::map<int, std::vector<int>>> ();
    g2_m = std::make_unique<std::map<int, std::vector<int>>> ();
    g2_f = std::make_unique<std::map<int, std::vector<int>>> ();
    g3_m = std::make_unique<std::map<int, std::vector<int>>> ();
    g3_f = std::make_unique<std::map<int, std::vector<int>>> ();

    g1 = std::make_unique<std::map<std::string, std::map<int, std::vector<int>>&>> ();
    g2 = std::make_unique<std::map<std::string, std::map<int, std::vector<int>>&>> ();
    g3 = std::make_unique<std::map<std::string, std::map<int, std::vector<int>>&>> ();

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
    //std::cout << "add" << std::endl;
    std::string gender {mGender};
    auto temp {db[mGrade - 1].at(gender).insert({mScore, {mId}})};
    if (!temp.second) {
        temp.first->second.push_back(mId);
    }
    loc.insert({mId, ((static_cast<int>(mGender[0]) << 22) | (mGrade << 20) | mScore)});
    auto it {std::end(db[mGrade - 1].at(gender))};
    std::advance(it, -1);
    return *std::max_element(std::begin(it->second), std::end(it->second));
}

int remove(int mId)
{
    //std::cout << "remov" << std::endl;
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
        for (auto vvit {std::begin(vit->second)}; vvit != std::end(vit->second); ++vvit) {
            if (*vvit == mId) {
                std::iter_swap(vvit, std::end(vit->second) - 1);
                vit->second.pop_back();
                break;
            }
        }
        loc.erase(mId);
        if (vit->second.empty())
            m.erase(score);
        if (m.empty()) return 0;

        auto& v {std::begin(m)->second};
        return *std::min_element(std::begin(v), std::end(v));
    }
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore)
{
    //std::cout << "query" << std::endl;
    auto result {std::pair<int, int> {1'000'000'001, 300'001}};
    for (auto i {0}; i != mGradeCnt; ++i) {
        for (auto j {0}; j != mGenderCnt; ++j) {
            auto gender {std::string{mGender[j]}};
            auto& m {db[mGrade[i] - 1].at(gender)};
            auto it {std::begin(m)};
            for (;it->first < mScore && it != std::end(m); ++it)
                ;
            if (it == std::end(m) || result.second < it->first) {
                continue;
            }
            else if (result.second == it->first) {
                auto min_id {*std::min_element(std::begin(it->second), std::end(it->second))};
                if (result.first > min_id)
                    result.first = min_id;
            }
            else {
                auto min_id {*std::min_element(std::begin(it->second), std::end(it->second))};
                result.first = min_id;
                result.second = it->first;
            }
        }
    }
    if (result.first == 1'000'000'001) return 0;
    return result.first;
}