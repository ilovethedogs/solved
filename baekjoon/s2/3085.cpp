#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto N {int{}};
    std::cin >> N;

    char v[50][50] {0};
    for (auto i {0}; i != N; ++i)
        for (auto j {0}; j != N; ++j)
            std::cin >> v[i][j];

    auto first_result {0};
    auto r_pivot {char{}};
    auto c_pivot {char{}};
    auto r_temp {1};
    auto c_temp {1};
    for (auto d {0}; d != N; ++d) {
        r_pivot = v[d][0];
        c_pivot = v[0][d];

        for (auto i {1}; i != N; ++i) {
            if (r_pivot == v[d][i]) {
                ++r_temp;
            }
            else {
                first_result = std::max(first_result, r_temp);
                r_pivot = v[d][i];
                r_temp = 1;
            }

            if (c_pivot == v[i][d]) {
                ++c_temp;
            }
            else {
                first_result = std::max(first_result, c_temp);
                c_pivot = v[i][d];
                c_temp = 1;
            }
        }
        first_result = std::max(first_result, r_temp);
        first_result = std::max(first_result, c_temp);
        r_temp = c_temp = 1;
    }


    for (auto r {0}; r != N; ++r) {
        for (auto c{0}; c != N; ++c) {
            if (r + 1 != N && v[r][c] != v[r + 1][c]) {
                std::swap(v[r][c], v[r + 1][c]);
                r_temp = c_temp = 1;
                for (auto d {0}; d != N; ++d) {
                    r_pivot = v[d][0];
                    c_pivot = v[0][d];

                    for (auto i {1}; i != N; ++i) {
                        if (r_pivot == v[d][i]) {
                            ++r_temp;
                        }
                        else {
                            first_result = std::max(first_result, r_temp);
                            r_pivot = v[d][i];
                            r_temp = 1;
                        }

                        if (c_pivot == v[i][d]) {
                            ++c_temp;
                        }
                        else {
                            first_result = std::max(first_result, c_temp);
                            c_pivot = v[i][d];
                            c_temp = 1;
                        }
                    }
                    first_result = std::max(first_result, r_temp);
                    first_result = std::max(first_result, c_temp);
                    r_temp = c_temp = 1;
                }
                std::swap(v[r][c], v[r + 1][c]);
            }

            if (c + 1 != N && v[r][c] != v[r][c + 1]) {
                std::swap(v[r][c], v[r][c + 1]);
                r_temp = c_temp = 1;
                for (auto d {0}; d != N; ++d) {
                    r_pivot = v[d][0];
                    c_pivot = v[0][d];

                    for (auto i {1}; i != N; ++i) {
                        if (r_pivot == v[d][i]) {
                            ++r_temp;
                        }
                        else {
                            first_result = std::max(first_result, r_temp);
                            r_pivot = v[d][i];
                            r_temp = 1;
                        }

                        if (c_pivot == v[i][d]) {
                            ++c_temp;
                        }
                        else {
                            first_result = std::max(first_result, c_temp);
                            c_pivot = v[i][d];
                            c_temp = 1;
                        }
                    }
                    first_result = std::max(first_result, r_temp);
                    first_result = std::max(first_result, c_temp);
                    r_temp = c_temp = 1;
                }
                std::swap(v[r][c], v[r][c + 1]);
            }
        }
    }
    std::cout << first_result;

    return EXIT_SUCCESS;
}