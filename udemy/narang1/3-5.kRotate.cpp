/* given an integer vector and a value k, your task is to rotate the array k times clockwise */

std::vector<int> kRotate(std::vector<int> a, int k) {
	std::vector<int> left {};
	size_t left_start { a.size() - (k % a.size()) };
	
	for (size_t i {left_start}; i != a.size(); ++i)
		left.push_back(a[i]);

	for (size_t i {0}; i != left_start; ++i)
		left.push_back(a[i]);

	return left;
}
