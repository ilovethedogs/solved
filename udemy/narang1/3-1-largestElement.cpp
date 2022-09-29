/* implement a function that takes array of integers as input and returns the largest element */

int largestElement(std::vector<int> arr) {
	auto largest { arr[0] };
	for (int i { 1 }; i != arr.size(); ++i)
		largest = max(largest, arr[i]);
	return largest;
}
