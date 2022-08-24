#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>

int main()
{
	std::ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	auto N {int{}};
	std::cin >> N;

	auto temp {int{}};
	auto result {0};
	auto cur_num {1};
	auto b {bool{false}};
	auto start {std::chrono::high_resolution_clock::now()};
	for (auto i {0}; i != N; ++i)
	{
		std::cin >> temp;
		b = (cur_num == temp);
		cur_num += b;
		result += !b;
	}
	auto end {std::chrono::high_resolution_clock::now() - start};

	std::cout << std::chrono::duration<double, std::milli> (end).count() << "ms" << '\n';

	std::cout << result;
	return EXIT_SUCCESS;
}