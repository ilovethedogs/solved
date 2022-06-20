#include <iostream>
#include <vector>

int main() {
    std::vector<int> a (0, 5);
    for (auto i : a) std::cout << i << " ";
    std::cout << std::endl; 
    return 0;
}