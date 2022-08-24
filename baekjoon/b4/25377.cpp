#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	auto N {int{}};
	std::cin >> N;

	auto temp1 {int{}};
	auto temp2 {int{}};
	auto result {1'001};
	for (auto i {0}; i != N; ++i)
	{
		std::cin >> temp1 >> temp2;
		if (temp2 >= temp1 && temp2 < result) result = temp2;
	}
	result = -1 * (result == 1'001) + result * (result != 1'001);
	std::cout << result;
	return EXIT_SUCCESS;
}