#include <iostream>
#include <string>

int main() {
    auto str {std::string {}};
    std::getline(std::cin, str);

    auto result {0};
    for (auto i {0}; i != str.size(); ++i) {
        if (result != 0 && str[i] != '0' && str[i] != '1')
            result *= static_cast<int>(str[i] - '0');
        else 
            result += static_cast<int>(str[i] - '0');
    }

    std::cout << result << std::endl;

    return 0;
}